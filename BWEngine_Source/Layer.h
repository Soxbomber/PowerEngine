#pragma once
#include "CommonInclude.h"
#include "Entity.h"
#include "GameObject.h"


namespace ya
{
	class Layer : public Entity
	{
	public:

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		void AddGameObject(GameObject* gameObject);

		Layer();
		~Layer();

	private:
		eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}
