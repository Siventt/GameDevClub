#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = { 173, 204, 96, 255 };
Color darkGreen = { 43, 51, 25, 255 };

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool running = true;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for(int i = 0; i < deque.size(); i++)
    {
        if(Vector2Equals(deque[i], element))
            return true;
    }
    return false;
}

Vector2 GenerateRandomCell()
{
    return {(float)GetRandomValue(0, cellCount - 1), 
            (float)GetRandomValue(0, cellCount - 1)};
}

struct Snake
{
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    Vector2 direction = {1, 0};
    bool eating = false;
    
    void draw()
    {
        for(int i = 0; i < body.size(); i++)
        {
            float x = body[i].x * cellSize + offset;
            float y = body[i].y * cellSize + offset;
            Rectangle segment = Rectangle{x, y, (float) cellSize, (float) cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }
    
    void update()
    {
        if(eating)
        {
            eating = false;
        } 
        else {
            body.pop_back();        
        }
        body.push_front(Vector2Add(body[0], direction));
    }
    
    void reset()
    {
        body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
        direction = {1, 0};
    }
};

struct Food
{
    Vector2 pos;
    Texture2D texture;
  
    Food(deque<Vector2> snakeBody)
    {
        Image image = LoadImage("resources/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        
        pos = generate_random_pos(snakeBody);
    }
  
    ~Food()
    {
        UnloadTexture(texture);
    }
  
    void draw()
    {
        DrawTexture(texture, pos.x * cellSize + offset, 
                    pos.y * cellSize + offset, WHITE);
    }
  
    Vector2 generate_random_pos(deque<Vector2> snakeBody)
    {   
        Vector2 random_pos;
        do {
            random_pos = GenerateRandomCell();
        } while(ElementInDeque(random_pos, snakeBody));
        return random_pos;
    }
};

struct Game
{
    Snake snake = Snake();
    Food food = Food(snake.body);
    int score = 0;
    Sound eatSound;
    Sound wallSound;
    
    Game()
    {
        eatSound = LoadSound("resources/sounds/eat.mp3");
        wallSound = LoadSound("resources/sounds/wall.mp3");
    }
    
    ~Game()
    {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
    }
    
    void draw()
    {
        food.draw();
        snake.draw();
    }
    
    void update()
    {
        if(running)
        {
            snake.update();
            check_eating_food();
            check_edge_collision();
            check_tail_collision();
        }
    }
    
    void check_input() 
    {
        if(IsKeyPressed(KEY_UP) and snake.direction.y != 1)
        {
	        snake.direction = {0, -1};
	        running = true;
	    }       
        if(IsKeyPressed(KEY_DOWN) and snake.direction.y != -1)
        {
            snake.direction = {0, 1};
            running = true;
        }
        if(IsKeyPressed(KEY_LEFT) and snake.direction.x != 1)
        {
            snake.direction = {-1, 0};
            running = true;
        }   
        if(IsKeyPressed(KEY_RIGHT) and snake.direction.x != -1)
        {
            snake.direction = {1, 0};
            running = true;
        }
    }
    
    void check_eating_food()
    {
        if(Vector2Equals(snake.body[0], food.pos))
        {
            food.pos = food.generate_random_pos(snake.body);
            snake.eating = true;
            score++;
            PlaySound(eatSound);
        }
    }
    
    void check_edge_collision()
    {
        if(snake.body[0].x >= cellCount or snake.body[0].x < 0 or
           snake.body[0].y >= cellCount or snake.body[0].y < 0)
        {
            game_over();
        }
        
    }
    
    void check_tail_collision()
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if(ElementInDeque(snake.body[0], headlessBody))
            game_over();
    }
    
    void game_over()
    {
        snake.reset();
        food.pos = food.generate_random_pos(snake.body);
        running = false;
        score = 0;
        PlaySound(wallSound);
    }
};

int main()
{
    InitWindow(cellSize*cellCount + 2*offset, cellSize*cellCount + 2*offset, "Raylib Snake");
    InitAudioDevice();
    if(true)
    {
        SetTargetFPS(60);
    
        Game game = Game();

        while (!WindowShouldClose())
        {
            // Eventos
	
	        game.check_input();
	
            // Actualizado
            
            if(EventTriggered(0.2)) // podria usarse como velocidad incremental, aniadiendo dificultad.
            {
                game.update();
            }
    
            //Dibujado
            BeginDrawing();
            ClearBackground(green);
            
            game.draw();
            
            DrawRectangleLinesEx( Rectangle{(float)offset-5, (float)offset-5, 
                                            (float)cellSize*cellCount+10, 
                                            (float)cellSize*cellCount+10},
                                  5, darkGreen);
            DrawText("Raylib Snake", offset -5, 20, 40, darkGreen);
            DrawText(TextFormat("%d", game.score), offset -5, offset+cellSize*cellCount+10,40, darkGreen);
            
            EndDrawing();
        }
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
