#include "TestClearColor.h"

#include "Renderer.h"
#include "imgui/imgui.h"

namespace test {

	TestClearColor::TestClearColor()
		: m_ClearColor{0.2f, 0.3f, 0.8f, 1.0f}
	{
	}

	TestClearColor::~TestClearColor()
	{
		GLCALL(glClearColor(0, 0, 0, 0));
		GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnUpdate(float daltaTime)
	{
	}

	void TestClearColor::OnRender()
	{
		GLCALL(glClearColor(m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]));
		GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_ClearColor);
	}
}