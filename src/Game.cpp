#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Game.h"

int main(void)
{
    Game game;
    if (!game.init())
    {
        return EXIT_FAILURE;
    }

    return game.run();
}

Game::Game()
    : glfwWindow(NULL),
      renderer(new Renderer()),
      input(new Input()),
      player(new Player()),
      map(new Map()),
      raycaster(new Raycaster())
{
}

Game::~Game()
{
    delete input;
    delete player;
    delete map;
    delete raycaster;
}

bool Game::init()
{
    //GLFW
    if (!glfwInit())
        return false;

    glfwWindow = glfwCreateWindow(1024, 1024, "MazeRaycaster", NULL, NULL);

    if (!glfwWindow)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(glfwWindow);

    //GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return false;

    //renderer
    if (!renderer->initRenderer(glfwWindow))
        return false;

    //set user pointer to handle input callbacks
    glfwSetWindowUserPointer(glfwWindow, input);

    //key input callback
    auto func = [](GLFWwindow* w, int key, int scancode, int action, int mods)
    {
        static_cast<Input*>(glfwGetWindowUserPointer(w))->keyPressed(key, action);
    };
    glfwSetKeyCallback(glfwWindow, func);

    
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);

    player->init();
    input->init(player);
    raycaster->init(player, map);
    map->init();

    return true;
}

bool Game::run()
{
    static double limitFPS = 1.0 / 60.0;

    double lastTime = glfwGetTime(), timer = lastTime;
    double deltaTime = 0, nowTime = 0;
    int frames = 0, updates = 0;

    while (!glfwWindowShouldClose(glfwWindow))
    {
        //measure time
        nowTime = glfwGetTime();
        deltaTime += (nowTime - lastTime) / limitFPS;
        lastTime = nowTime;

        while (deltaTime >= 1.0) {
            update();
            updates++;
            deltaTime--;
        }

        display();
        
        frames++;

        if (glfwGetTime() - timer > 1.0) {
            timer++;
            std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
            updates = 0, frames = 0;
        }
    }

    glfwTerminate();
    return true;
}

void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    raycaster->drawGame();

    if (input->showMap) {
        map->draw();
        player->draw();
        raycaster->drawMap();
    }

    glfwSwapBuffers(glfwWindow);
}

void Game::update()
{
    raycaster->castRays();
    glfwPollEvents();
}