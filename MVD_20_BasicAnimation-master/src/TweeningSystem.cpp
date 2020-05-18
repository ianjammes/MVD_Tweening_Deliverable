#include "CollisionSystem.h"
#include "TweeningSystem.h"
#include "extern.h"

void TweeningSystem::update(float dt) {

	auto& tweening = ECS.getAllComponents<Tweening>();

	for (auto& tween : tweening) {

		Transform& transform = ECS.getComponentFromEntity<Transform>(tween.owner);

		tween.p0.position(0, 0, 0);
		tween.p1.position(20, 10, 30);

		lm::vec3 p0p1 = tween.p1.position() - tween.p0.position();

		//Rotation
		lm::quat qrot(tween.rotValue, 0, tween.rotValue);
		transform.makeRotationMatrix(qrot * tween.d);

		//Position
		transform.position(tween.p0.position().x + p0p1.x * tween.d,
							tween.p0.position().y + p0p1.y * tween.d,
				            tween.p0.position().z + p0p1.z * tween.d);

	
		

		if (transform.position().x <= tween.p1.position().x)
			tween.d +=0.0003;
		
	}

	

}