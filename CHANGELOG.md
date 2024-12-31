## [0.2.9] 2024-12-31
- 基本api12重新打包
---
## [0.2.8] 2024-12-26

- 更新README中关于NativeImages说明

---

## [0.2.7] 2024-12-26

- 移除NativeImage的isAvailable，改成
  setOnFrameAvailableListener(callback: Function): number
  /unSetOnFrameAvailableListener(): number

---

## [0.2.6] 2024-12-25

- 原来这type文件一直没打包进去啊！！！！

---

## [0.2.5] 2024-12-24

- 修复NativeImage无法创建

---

## [0.2.4] 2024-12-24

- NativeImage增加Sendable装饰器，可以在多线程中操作
- 封装方法增加Sendable支持
- 增加GLES构造函数（方便后续glview中的GLRender中传递，移除@jemoc/gles直接暴露）
- 修复部分入参问题

---

## [0.2.3] 2024-12-18

- NativeImage可用帧改用原子操作
- NativeImage增加destroy方法

---

## [0.2.2] 2024-12-17

- 新增NativeImage实现同层渲染
- 增加GL_TEXTURE_EXTERNAL_OES常量
- Program中增加ivec支持，支持glUniformi*方法

---

## [0.2.1] 2024-12-12

- 修复glShaderSource写入错误
- 更改glAttachShader (program: number, shader: number) => void 改成 (program: number, ...shader: number[]) => void;

## [0.2.0] 2024-12-12

- 封装Buffer、VertexBuffer、VertexArray、Texture、Program、shader等方法
- 增加glVertexAttribFormat、glVertexAttribIFormat
- 不提供glMapBufferRange（暂时）
- 后续可能会继续增加glVertexAttribBinding等封装，继续优化方法的调用，增加向量和矩阵的操作

---

## [0.1.0] - 2024-12-05

- 整理文件，添加type

---

## [0.0.3] - 2024-11-21

### Fixed

- 修复glDelete等方法传入参数获取数组大小错误

### Added

- 增加缺失的glDeleteVertexArrays方法

---

## [0.0.2] - 2024-11-20

### Info

- 合并gles10和gles

### Fixed

- 修复arkTs侧传入ArrayBufferLike时，native侧读取错误的问题

---

## [0.0.1] - 2024-11-19

### Info

进行基本测试

### Added

- gles模块包含opengl基本方法
- gles10模块包含opengl常量