#version 330 core

out vec4 FragColor;

in vec3 pos_world;
in vec3 norm_world;

vec3 Normalize(vec3 pos)
{
    normalize(pos);
    pos /= 2.0f;
    pos += 0.5f;

    return pos;
}

uniform vec3 camera_pos;
uniform vec3 light_pos;
uniform vec3 object_color;
uniform vec3 light_color;

vec3 phong_shading()
{
    vec3 camera_dir = normalize(camera_pos - pos_world);
    vec3 light_dir = normalize(light_pos - pos_world);
    vec3 half_vec = normalize(light_dir + camera_dir);

    vec3 ambient_color = object_color * 0.06;
    vec3 diffuse_color = max(0.0,dot(norm_world,light_dir)) * 0.45 * object_color;
    vec3 specular_color = pow(max(0.0,dot(half_vec,norm_world)),32) * 0.75 * object_color;

    return ambient_color + diffuse_color + specular_color;
}

void main()
{
    vec3 color = phong_shading();
    FragColor = vec4(color * light_color,1.0);
}
