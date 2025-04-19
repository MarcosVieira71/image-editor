#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

int main()
{
    // Criação da janela SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "ImGui + SFML");

    // Inicializa o ImGui com SFML
    ImGui::SFML::Init(window);

    // Clock para controle de tempo
    sf::Clock deltaClock;

    while (window.isOpen())
    {
        // Processamento de eventos SFML
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Inicia o novo quadro do ImGui
        ImGui::SFML::Update(window, deltaClock.restart());

        // Limpeza da janela SFML
        window.clear();

        // Começa a criação de widgets do ImGui
        ImGui::Begin("Demo Window");
        ImGui::Text("Hello, world!");
        if (ImGui::Button("Click me"))
        {
            ImGui::Text("Button Clicked!");
        }
        ImGui::End();

        // Renderiza a interface do ImGui
        ImGui::SFML::Render(window);

        // Exibe o conteúdo da janela
        window.display();
    }

    // Finaliza o ImGui
    ImGui::SFML::Shutdown();
    return 0;
}
