#include "gui.h"
#include <thread>
#include "../imgui/imgui.h"
#include "globals.h"	
#include "inject/inject.h"

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE prevInstance,
	PWSTR args,
	int commandShow)
{
	gui::CreateHWindow("dxd9", "gui-1");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit)
	{
		gui::BeginRender();
		gui::Render();



		ImGui::NextColumn();
		if (ImGui::Button("main", { 237,20 }))
		{
			menu::tab = 0;
			
		}
		ImGui::SameLine();
		if (ImGui::Button("info", { 237,20 }))
		{
			menu::tab = 1;
		}

		if (menu::tab == 0)	//main
		{
			

			ImGui::Separator();
			const char* choice[] = { "choice1", "choice2", "choice3" };
			static int selected = 0;
			ImGui::Combo("option", &selected, choice, IM_ARRAYSIZE(choice));

			if (selected == 0)
			{
				ImGui::Text("example_text");
				ImGui::SameLine();
				if (ImGui::Button("button", { 200, 20 }) && selected == 0)
				{
					inject::Fake_Inject();
				}


			}
			if (selected == 1)
			{
				ImGui::Text("you selected choice2");
				ImGui::SameLine();
				


			}
			if (selected == 2)
			{
				ImGui::Text("you selected choice3");
				ImGui::SameLine();
				


			}
			
			
			
		}

		if (menu::tab == 1)	//info
		{
			ImGui::Separator();
			ImGui::NewLine();
			ImGui::Text("Status:"); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 0), "Unknown");
			ImGui::NewLine();
			ImGui::Text("user info:");
			ImGui::Text("tab: %i", menu::tab);
			ImGui::Text("float = %.4f", 0.99214f);
			ImGui::Text("placeholder : *************************");
			ImGui::NewLine();
			ImGui::NewLine();
			ImGui::Text("more info:");
			ImGui::Text("choice1: "); ImGui::SameLine(); ImGui::TextColored(ImColor(0, 255, 0), "Green");
			ImGui::Text("choice2: "); ImGui::SameLine(); ImGui::TextColored(ImColor(255, 0, 0), "Red");
			ImGui::Text("choice3: "); ImGui::SameLine(); ImGui::TextColored(ImColor(255, 255, 0), "Yellow");
			ImGui::NewLine();
			ImGui::SameLine();
			ImGui::NextColumn();
			if (ImGui::Button("close", { 150, 20 }))
			{
				gui::exit = 0;
			}
			
		}
		



		ImGui::End();
		gui::EndRender();






		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyWindow();



	return EXIT_SUCCESS;
}