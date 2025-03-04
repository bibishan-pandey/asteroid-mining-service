#include "EntryPoint.h"
#include "framework/Application.h"

int main() {
    mining_simulation::Application *app = GetApplication();
    app->Run();

    delete app;
}
