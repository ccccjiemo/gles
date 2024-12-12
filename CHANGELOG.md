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