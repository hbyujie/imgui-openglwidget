
#pragma once

#include <glm/glm.hpp>
#include <unordered_map>
#include <vector>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texcoord;
    glm::vec4 color;
    glm::vec3 tangent;
    glm::vec3 bitangent;
};

struct Texture
{
    unsigned int id{0};
    std::string file_name{""};
    int width, height;
    int levels;
    bool is_vertical_flip{true};
};

struct Textures
{
    Texture albedo;
    Texture normal;
    Texture metallic;
    Texture roughness;
    Texture ao;
};

struct Material
{
};

struct PartsMesh
{
    unsigned int vao{0};
    unsigned int vbo{0};
    std::vector<Vertex> vertices;

    Textures textures;
    Material material;
};
