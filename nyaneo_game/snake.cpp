#include "snake.h"

// struct Snake snake;
// struct TailNode *lasttail;

// void push_tail();
// Snake::Snake()
// {
//         snakeHead = (SnakeHead*)malloc(sizeof(struct SnakeHead));
//         lastTail = (TailNode*)malloc(sizeof(struct TailNode));
// }
// Snake::~Snake()
// {
//     free(snakeHead);
//     free(lastTail);
// }

bool Snake::init_snake()
{
    // default direction
    snakeHead->dx = -1;
    snakeHead->dy = 0;
    // snake.dx = -1;
    // snake.dy = 0;

    // initializes head
    snakeHead->head.rect.x = DEFAULT_X;
    snakeHead->head.rect.y = DEFAULT_Y;
    snakeHead->head.rect.w = DEFAULT_WIDTH;
    snakeHead->head.rect.h = DEFAULT_HEIGHT;

    // snake.head.rect.x = DEFAULT_X;
    // snake.head.rect.y = DEFAULT_Y;
    // snake.head.rect.w = DEFAULT_WIDTH;
    // snake.head.rect.h = DEFAULT_HEIGHT;
    // snake.head.next = NULL;
    // snake.head.previous = NULL;
    snakeHead->head.next = NULL;
    snakeHead->head.previous = NULL;

    // sets pointer of last tail to head
    lastTail = &snakeHead->head;

    // pushes default tails
    for (int i = 0; i < DEFAULT_TAILS_N; ++i)
        push_tail();

    return true;
}


void Snake::render_tail(SDL_Rect* tail, Graphics* graphics)
{   // renders individual parts of the snake
    SDL_SetRenderDrawColor(graphics->getRenderer(), 252, 191, 30, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(graphics->getRenderer(), tail);
}

void Snake::check_collision(Apple* apple)
{
    // fruit collision
    if (abs(snakeHead->head.rect.x - apple->get_apple_posX()) < DEFAULT_WIDTH && abs(snakeHead->head.rect.y - apple->get_apple_posY()) < DEFAULT_HEIGHT) {
        push_tail();
        apple->generate_new_apple_pos();
    }

    // border collision
    if (snakeHead->head.rect.x > SCREEN_WIDTH - DEFAULT_WIDTH)
        snakeHead->head.rect.x = 0;
    else if (snakeHead->head.rect.x < 0 - DEFAULT_WIDTH)
        snakeHead->head.rect.x = SCREEN_WIDTH;
    else if (snakeHead->head.rect.y < 0 - DEFAULT_HEIGHT)
        snakeHead->head.rect.y = SCREEN_HEIGHT;
    else if (snakeHead->head.rect.y > SCREEN_HEIGHT - DEFAULT_HEIGHT)
        snakeHead->head.rect.y = 0;
}

void Snake::update_snake(Apple* apple, Graphics* graphics)
{   // iterates over the head and the tail
    for (struct TailNode* ptr = lastTail; ptr != NULL; ptr = (*ptr).previous) {
        if ((*ptr).previous == NULL) { // in other words, if this "tail" is the head
            snakeHead->head.rect.x += snakeHead->dx * DEFAULT_WIDTH;
            snakeHead->head.rect.y += snakeHead->dy * DEFAULT_HEIGHT;
        }
        else { // if it's the snake's body
            if (abs(snakeHead->head.rect.x - (*ptr).rect.x) < DEFAULT_WIDTH && // checks collision with the head
                abs(snakeHead->head.rect.y - (*ptr).rect.y) < DEFAULT_HEIGHT)
                quit_game();

            (*ptr).rect.x = (*ptr).previous->rect.x;
            (*ptr).rect.y = (*ptr).previous->rect.y;
        }

        render_tail(&(*ptr).rect, graphics);
    }

    check_collision(apple); // head-only collision (fruit, border, etc.)
}

void Snake::push_tail()
{   // pushes a new tail inside the linked list
    struct TailNode* new_tail = (TailNode*)malloc(sizeof(struct TailNode));
    if (new_tail == NULL)
        quit_game();

    (*new_tail).rect.w = DEFAULT_WIDTH;
    (*new_tail).rect.h = DEFAULT_HEIGHT;

    (*new_tail).next = NULL;
    (*new_tail).previous = lastTail;

    (*lastTail).next = new_tail;
    lastTail = new_tail;
}

void Snake::change_snake_direction(int dir)
{
    if (dir == RIGHT && snakeHead->dx != -1) {
        snakeHead->dx = 1;
        snakeHead->dy = 0;
    }
    else if (dir == LEFT && snakeHead->dx != 1) {
        snakeHead->dx = -1;
        snakeHead->dy = 0;
    }
    else if (dir == UP && snakeHead->dy != 1) {
        snakeHead->dy = -1;
        snakeHead->dx = 0;
    }
    else if (dir == DOWN && snakeHead->dy != -1) {
        snakeHead->dy = 1;
        snakeHead->dx = 0;
    }
}

void Snake::free_tails()
{
    struct TailNode* tmp;
    struct TailNode* secondtail;
    secondtail = snakeHead->head.next; // we skip the first node (head) because it's allocated in the stack

    while (secondtail != NULL) {
        tmp = secondtail;
        secondtail = (*secondtail).next;
        free(tmp);
    }
}