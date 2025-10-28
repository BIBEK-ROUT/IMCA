import pygame
import random
import sys

# Constants
WIDTH, HEIGHT = 600, 400
CELL = 20
FPS = 5

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (220, 20, 60)

# Init
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()
font = pygame.font.SysFont("consolas", 24)

# Helper Functions
def draw_rect(pos, color):
    pygame.draw.rect(screen, color, (*pos, CELL, CELL))

def get_random_position():
    return (
        random.randint(0, (WIDTH - CELL) // CELL) * CELL,
        random.randint(0, (HEIGHT - CELL) // CELL) * CELL,
    )

# Game Logic
def reset_game():
    return {
        "snake": [(CELL*5, CELL*5)],
        "direction": (CELL, 0),
        "food": get_random_position(),
        "score": 0,
        "dead": False
    }

def draw_game(state):
    screen.fill(BLACK)
    for segment in state["snake"]:
        draw_rect(segment, GREEN)
    draw_rect(state["food"], RED)
    text = font.render(f"Score: {state['score']}", True, WHITE)
    screen.blit(text, (10, 10))
    pygame.display.flip()

def update_snake(state):
    head = state["snake"][0]
    dx, dy = state["direction"]
    new_head = (head[0] + dx, head[1] + dy)

    # Collision: Wall or Self
    if (new_head in state["snake"] or
        new_head[0] < 0 or new_head[0] >= WIDTH or
        new_head[1] < 0 or new_head[1] >= HEIGHT):
        state["dead"] = True
        return

    state["snake"].insert(0, new_head)

    # Eat food
    if new_head == state["food"]:
        state["food"] = get_random_position()
        state["score"] += 1
    else:
        state["snake"].pop()

def handle_input(state):
    keys = pygame.key.get_pressed()
    dir_map = {
        pygame.K_UP: (0, -CELL),
        pygame.K_DOWN: (0, CELL),
        pygame.K_LEFT: (-CELL, 0),
        pygame.K_RIGHT: (CELL, 0)
    }
    for key, new_dir in dir_map.items():
        if keys[key] and (new_dir[0] != -state["direction"][0] or new_dir[1] != -state["direction"][1]):
            state["direction"] = new_dir
            break

# Main Loop
def main():
    state = reset_game()

    while True:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if state["dead"] and event.type == pygame.KEYDOWN:
                state = reset_game()

        if not state["dead"]:
            handle_input(state)
            update_snake(state)

        draw_game(state)

if __name__ == "__main__":
    main()
