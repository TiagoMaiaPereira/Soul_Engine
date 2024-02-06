#pragma once
#include "spch.h"
#include "Component.h"

#include "Renderer.h"
#include "Texture.h"

#include "PhysWorld.h"
#include "Engine.h"

namespace Soul
{
	

	struct SpriteComponent : public Component
	{

		SpriteComponent() = default;

		SpriteComponent(const char* path)
		{

		}

		void Start() override
		{

		}

		void UpdateComponent(float deltaTime) override
		{
		}

		void DrawComponent() override
		{
		}
	};

	struct AnimatorComponent : public Component {

		struct Animation;
		struct AnimationFrame;

		AnimatorComponent() = default;

		AnimatorComponent(std::shared_ptr<Texture2D>& texture)
			: m_Texture(texture)
		{
		}

		~AnimatorComponent() {
		}

		void Start() override
		{
		}

		void UpdateComponent(float deltaTime) override
		{

		}

		void DrawComponent() override
		{

		}

		void SetStartFrame(AnimationFrame&& frame) {
			if (m_Texture->t_PixelSize == -1) {
				std::cout << "Specify a pixel size when creating a SpriteRenderer2D" << std::endl;
			}
			else {
				int frameX = frame.f_x * m_Texture->t_PixelSize;
				int frameY = frame.f_y * m_Texture->t_PixelSize;
				m_Texture->srcRect->x = frameX;
				m_Texture->srcRect->y = frameY;
			}
		}

		void CreateAnimation(Animation* animation) {
			m_Animations.emplace_back(animation);
		}

		void PlayAnimationContiniousToFrame(std::string animationName, float frameRate, float deltaTime, bool looping)
		{
			Animation* a = FindAnimation(animationName);

			time += deltaTime;

			if (!a->a_Finished) {
				if (time >= frameRate)
				{
					time = 0;

					if (a->a_CurrentFrame.f_x * m_Texture->t_Size.x >= m_Texture->GetWidthF()) {
						a->a_CurrentFrame.f_x = 0;
						a->a_CurrentFrame.f_y += 1;
						if (a->a_CurrentFrame.f_y * m_Texture->t_Size.y >= m_Texture->GetHeightF()) {
							if (looping) {
								a->a_CurrentFrame = a->a_Frames[0];
							}
							else {
								a->a_Finished = true;
							}
						}
					}

					m_Texture->srcRect->x = a->a_CurrentFrame.f_x * m_Texture->t_Size.x;
					m_Texture->srcRect->y = a->a_CurrentFrame.f_y * m_Texture->t_Size.y;
					a->a_CurrentFrame.f_x += 1;
				}
			}

		}

		void PlayAnimation(std::string animationName, float frameRate, float deltaTime, bool looping) {
			Animation* a = FindAnimation(animationName);
			if (!a->a_Finished) {
				time += deltaTime;
				if (time >= frameRate) {
					int nextFrame = GetNextFrame(*a, m_Texture->srcRect->x, m_Texture->srcRect->y);

					if (a->a_Frames.size() == nextFrame) {
						if (looping) {
							nextFrame = 0;
							m_Texture->srcRect->x = a->a_Frames[nextFrame].f_x * m_Texture->t_Size.x;
							m_Texture->srcRect->y = a->a_Frames[nextFrame].f_y * m_Texture->t_Size.y;
							a->a_Finished = false;
						}
					}
					else {

						time = 0;
						m_Texture->srcRect->x = a->a_Frames[nextFrame].f_x * m_Texture->t_Size.x;
						m_Texture->srcRect->y = a->a_Frames[nextFrame].f_y * m_Texture->t_Size.y;
					}
				}
			}
		}

		bool IsPlayingAnimation(std::string animationName) {
			Animation* a = FindAnimation(animationName);
			return !a->a_Finished;
		}

	private:
		Animation* FindAnimation(std::string& name) {
			for (Animation* a : m_Animations)
			{
				if (a->animName == name) {
					return a;
				}
			}

			//not found animation
		}

		int GetNextFrame(Animation a, int x, int y)
		{
			for (int i = 0; i < a.a_Frames.size(); ++i)
			{
				if ((a.a_Frames[i].f_x * m_Texture->t_Size.x) == x && (a.a_Frames[i].f_y * m_Texture->t_Size.y) == y) {
					if (i + 1 < a.a_Frames.size()) {
						return i + 1;
					}
					else {
						return a.a_Frames.size();
					}
				}
			}

			return 0;
		}

	public:
		std::shared_ptr<Texture2D> m_Texture;

		std::vector<Animation*> m_Animations = {};

		struct AnimationFrame {
			AnimationFrame() {}
			AnimationFrame(int x, int y)
			{
				f_x = x - 1;
				f_y = y - 1;
			}

			int f_x;
			int f_y;
		};

		struct Animation {
			Animation(std::string name, std::vector<AnimationFrame> frames)
				: animName(name), a_Frames(frames)
			{
				a_CurrentFrame = frames[0];
			}

			std::string animName;
			std::vector<AnimationFrame> a_Frames;
			AnimationFrame a_CurrentFrame;
			bool a_Finished = false;
		};

	private:
		float time = 0;

	};



}