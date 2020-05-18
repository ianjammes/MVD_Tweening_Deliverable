#include "CollisionSystem.h"
#include "extern.h"
#include "AnimationSystem.h"
#include "extern.h"

void AnimationSystem::update(float dt) {

	//acces our animation components and do stuff with them
	auto& anims = ECS.getAllComponents<Animation>();

	//loop all animation components
	for (auto& anim : anims) {

		Transform& transform = ECS.getComponentFromEntity<Transform>(anim.owner);

		anim.ms_counter += dt * 1000;
		if(anim.ms_counter >= anim.ms_frame)
		{

			anim.ms_counter = anim.ms_counter - anim.ms_frame;


			//set transform
			transform.set(anim.keyframes[anim.curr_frame]);


			anim.curr_frame++;

			if (anim.curr_frame == anim.num_frame)
				anim.curr_frame = 0;
		}

		
	}

	

}