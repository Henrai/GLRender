//
// Created by Anze Wang on 1/31/23.
//

#include "Renderer.h"

#include <iostream>
#include "glad/glad.h"

#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

void GLClearError() {
    while(glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
            " " << file << " " << line << std::endl;
        return false;
    }
    return true;
}
void Renderer::initShader(const std::string &path) {
    mShader = std::make_unique<Shader>(path);
}

void Renderer::appendTexture(const std::string &path,const std::string& name , unsigned int format) {
    mShader->Bind();
    std::unique_ptr<Texture> texture = std::make_unique<Texture>(path, format);
    texture->Bind(mTextures.size());
    mShader->setUniform1i(name, mTextures.size());
    mShader->UnBind();
    mTextures.push_back(std::move(texture));
}

void Renderer::initVertexData(float *vertices, unsigned int vlen, unsigned int* indices, unsigned int ilen, std::vector<int> layout) {
    mVertexArray = std::make_unique<VertexArray>();
    mVertexBuffer = std::make_unique<VertexBuffer>(vertices, vlen * sizeof(float ));

    VertexBufferLayout bufferLayout;
    for(auto i:layout) {
        bufferLayout.Push<float>(i);
    }
    mVertexArray->AddBuffer(*mVertexBuffer, bufferLayout);
     mIndexBuffer = std::make_unique<IndexBuffer>(indices, 6);
    mIndexBuffer->UnBind();
    mVertexBuffer->UnBind();
    mShader->UnBind();
}

Shader& Renderer::getShader() {
    return *mShader;
}


void Renderer::draw() const {
    mShader->Bind();
    mVertexArray->Bind();
    mIndexBuffer->Bind();
    for(int i = 0; i < mTextures.size(); i++)
        mTextures[i]->Bind(i);
    GL_CALL(glDrawElements(GL_TRIANGLES, mIndexBuffer->GetSize(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::setUniform1i(const std::string &name, int v) {
    mShader->Bind();
    mShader->setUniform1i(name, v);
}

void Renderer::setUniform1f(const std::string &name, float v) {
    mShader->Bind();
    mShader->setUniform1f(name, v);
}

void Renderer::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
    mShader->Bind();
    mShader->setUniform4f(name, v0, v1, v2, v3);
}

void Renderer::unBind() {
    mShader->UnBind();
    mVertexArray->UnBind();
    mIndexBuffer->UnBind();
}