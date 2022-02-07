#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model_mat;
uniform mat4 view_mat;
uniform mat4 projection_mat;

out vec3 pos_world;
out vec3 norm_world;

void main()
{
   pos_world = (model_mat * vec4(aPos.x, aPos.y, aPos.z, 1.0)).xyz;
   norm_world = aNorm;
   gl_Position = projection_mat * view_mat * model_mat * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}