#include "Corepch.h"
#include "LayerStack.h"


namespace Core {
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerEnterIndex, layer);
		m_LayerEnterIndex++;
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin(), layer);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
			m_LayerEnterIndex--;
		}

	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin(), overlay);

		if (it != m_Layers.end()) {
			m_Layers.erase(it);
		}
	}
}
