#pragma once

#include "Event.h"
#include "hzpch.h"

namespace Hazel {
	class HAZEL_API MouseMoveEvent :public Event {
	public:
		MouseMoveEvent(float x, float y) :
			m_MouseX(x), m_MouseY(y) {	}
		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMoveEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVTNT_CLASS_CATEGOTY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) :
			m_Xoffset(xOffset), m_Yoffset(yOffset) {}

		inline float GetXoffset() { return m_Xoffset; }
		inline float GetYoffset() { return m_Yoffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_Xoffset << ", " << m_Yoffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVTNT_CLASS_CATEGOTY(EventCategoryInput | EventCategoryMouse)
	private:
		float m_Xoffset, m_Yoffset;
	};

	class HAZEL_API MouseButtonEvent :public Event {
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVTNT_CLASS_CATEGOTY(EventCategoryInput | EventCategoryMouse)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}
		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent :public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}