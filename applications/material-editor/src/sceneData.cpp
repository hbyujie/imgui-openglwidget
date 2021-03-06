
#include "src/sceneData.h"
#include "opengl/gl_mesh.h"
#include "opengl/gl_shader.h"
#include "opengl/model/model_reader.h"

#include "opengl/gl_light.h"

#include "opengl/geometry/geometry_creator.h"

SceneData *SceneData::m_instance = nullptr;

SceneData *SceneData::Instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new SceneData;
    }
    return m_instance;
}

void SceneData::Delete()
{
    if (m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}

SceneData::SceneData(QObject *parent) : QObject(parent), m_data_dir("D:/imgui-openglwidget/data/")
{
    m_shaders["BlinnPhong"] =
        std::make_shared<GLShader>((m_data_dir + "shader/blinnPhong.vs"), (m_data_dir + "shader/blinnPhong.fs"));

    m_light = std::make_shared<GLLight>();
    m_light->InitDirectLight();
    m_light->InitPointLights();
	m_light->InitSpotLights();

	m_meshes["cube"] = std::make_shared<GLMesh>();
	GeometryCreator::GetCube(m_meshes["cube"]);

	//m_meshes["cube"]->SetShaderName("BlinnPhong");
	m_meshes["cube"]->Upload();
}

SceneData::~SceneData()
{
}

void SceneData::AddModel(const std::string &file_name)
{
    if (m_meshes.find(file_name) != m_meshes.end())
    {
        return;
    }

    m_meshes[file_name] = std::make_shared<GLMesh>();
    ModelReader reader(file_name, m_meshes[file_name]);

    m_meshes[file_name]->SetShaderName("BlinnPhong");
    m_meshes[file_name]->Upload();
}