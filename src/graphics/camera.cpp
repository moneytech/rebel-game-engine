#include "../rebel.h"
#include "../data/vec3.hpp"
#include "camera.h"
#include <cstdlib>

Camera* CameraCreate()
{
	Camera *camera = (Camera*)malloc(sizeof(Camera));
	camera->projection = CameraProjection::PERSPECTIVE;
	camera->size = 5;
	camera->fov = 45;
	camera->position = Vec3Create(0, 0, -10);
	camera->front = Vec3Create(0, 0, 1);
	camera->up = Vec3Create(0, 1, 0);
	camera->yaw = 90.0f;
	camera->pitch = 0.0f;
	return camera;
}

void CameraUpdateVectors(Camera* camera)
{
	glm::vec3 front;
	front.x = cos(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
	front.y = sin(glm::radians(camera->pitch));
	front.z = sin(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
	front = glm::normalize(front);

	camera->front->x = front.x;
	camera->front->y = front.y;
	camera->front->z = front.z;
}

void CameraMove(Camera *camera, enum Direction direction, float velocity)
{
	if ( direction == FORWARD )
	{
		glm::vec3 front = Vec3ToGlm(*camera->front);
		glm::vec3 position = Vec3ToGlm(*camera->position);
		position += front * velocity;
		Vec3FromGlm(camera->position, position);
	}
}
