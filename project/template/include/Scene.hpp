#pragma once
#include <glimac/SDLWindowManager.hpp>
#include "Model.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Skybox.hpp"
#include "Light.hpp"
#include "Checkpoint.hpp"
#include "MousePicker.hpp"
#include "ModelPicker.hpp"
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>

using namespace std;
using namespace glimac;


class Scene
{
    public:
      Scene(string path_season);
      void loadScene(string path_season);
      void render(SDLWindowManager* windowManager, float screenWidth, float screenHeight);
      void changeCheckpoint(SDLWindowManager* windowManager, bool sens);

    private:

      int nbCheckpoints;
      Checkpoint currentCheckpoint;
      Checkpoint firstCheckpoint;
      Checkpoint lastCheckpoint;

      map<string, Shader> shaders;
      map<string, Model> models;
      map<string, Checkpoint> checkpoints;

      map<string, Light*> lights;

      Camera camera;
      Skybox skybox;

      GLfloat deltaTime;
      GLfloat lastFrame;
      
      void initShaders(string shader_name, float screenWidth, float screenHeight);
      void initLights(string shader_name);
      void drawModels(string shader_name);
      void drawCheckpoints(string shader_name);
      void drawSkybox(float screenWidth, float screenHeight);
      void moveCamera(SDLWindowManager* windowManager);
};
