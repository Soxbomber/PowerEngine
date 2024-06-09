#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

namespace ya
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, enums::eLayerType type);
		Layer* GetLayer(enums::eLayerType type){ return mLayers[(UINT)type]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}


