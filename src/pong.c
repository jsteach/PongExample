#include "entrypoint.h"

#include "raylib.h"

typedef struct {
    Rectangle rect;
    Color color;
}Paddle;

typedef enum {
    PLAYER,
    AI,
    PTYPE_MAX
} PaddleType;

typedef struct {
    Vector2 pos;
    Vector2 vel;
    float radius;
}Ball;

#define WIN_W 1080
#define WIN_H 720

Paddle paddles[2] = {0};
Ball ball = {0};

#define SPEED 200

void update_player_paddle(float dt){
    if(IsKeyDown(KEY_W)){
        paddles[PLAYER].rect.y -= SPEED * dt;
    }
    else if(IsKeyDown(KEY_S)){
        paddles[PLAYER].rect.y += SPEED * dt;
    }
}

void update_ai_paddle(float dt){

}

void update_ball(float dt){

}

void raylib_start(void){
    InitWindow(WIN_W,WIN_H,"Pong");

    paddles[PLAYER].rect = CLITERAL(Rectangle){.x=0,.y=WIN_H *0.5f - WIN_W*0.1f,.width=WIN_W*0.05f, .height=WIN_W*0.1f};
    paddles[PLAYER].color = BLUE;
    paddles[AI].rect = CLITERAL(Rectangle){.x=WIN_W - WIN_W*0.05f,.y=WIN_H *0.5f - WIN_W*0.1f,.width=WIN_W*0.05f, .height=WIN_W*0.1f};
    paddles[AI].color = RED;
    ball.radius = WIN_W*0.025f;
    ball.pos = CLITERAL(Vector2){.x=WIN_W *0.5f - WIN_W*0.025f,.y=WIN_H *0.5f - WIN_W*0.025f};

    while(!WindowShouldClose()){
        float dt = GetFrameTime();

        update_player_paddle(dt);
        update_ai_paddle(dt);

        BeginDrawing();
        ClearBackground(WHITE);
        for(int i =0; i < PTYPE_MAX;++i){
            DrawRectangleRec(paddles[i].rect,paddles[i].color);
        }
        DrawCircle(ball.pos.x,ball.pos.y,ball.radius,BLACK);
        EndDrawing();
    }
}