## @jemoc/gles

---

### 下载安装

```shell
ohpm install @jemoc/gles
```

---

### 基本用法

#### 导入库
```typescript
import { gles } from '@jemoc/gles';
```

#### 使用opengl定义的GLenum类型值
```typescript
//使用枚举类型
gles.glClear(gles.GLbitfield.GL_COLOR_BUFFER_BIT);
//直接使用
gles.glClear(gles.GL_COLOR_BUFFER_BIT);
```

#### 绘制三角形
```typescript
let vertex_list = new Float32Array([
  -0.5, -0.5, 0.0,
  0.5, -0.5, 0.0,
  0.0,  0.5, 0.0
]);

//申请buffer
let bufs = gles.glGenBuffers(1);
let vbo = bufs[0];
gles.glBindBuffer(gles.GL_ARRAY_BUFFER, vbo);
gles.glBufferData(gles.GL_ARRAY_BUFFER, vertex_list, gles.GL_STATIC_DRAW);


let vertexShaderSource =
  `version 300 es
        layout(location = 0) in vec4 a_position;
        layout(location = 1) in vec4 a_color;
        out vec4 v_color;
        void main()
        {
            gl_Position = a_position;
            v_color = a_color;
        }`;

let fragmentShaderSource =
  `#version 300 es
      precision mediump float;
      in vec4 v_color;
      out vec4 fragColor;
      {
          fragColor = v_color;
      }`;

let program = gles.glCreateProgram();
let vertexShader = gles.glCreateShader(gles.GL_VERTEX_SHADER);
let fragmentShader = gles.glCreateShader(gles.GL_FRAGMENT_SHADER);

gles.glShaderSource(vertexShader, vertexShaderSource);
gles.glCompileShader(vertexShader);
let result = gles.glGetShaderiv(vertexShader, gles.GL_COMPILE_STATUS);

if(!result){
  let info = gles.glGetShaderInfoLog(vertexShader);
}

gles.glShaderSource(fragmentShader, fragmentShaderSource);
gles.glCompileShader(vertexShader);
result = gles.glGetShaderiv(fragmentShader, gles.GL_COMPILE_STATUS);

if(!result){
  let info = gles.glGetShaderInfoLog(fragmentShader);
}

gles.glAttachShader(program, vertexShader);
gles.glAttachShader(program, fragmentShader);
gles.glLinkProgram(program);

let status = gles.glGetProgramiv(program, gles.GL_LINK_STATUS);
if(!status){
  let info = gles.glGetProgramInfoLog(program);
}

gles.glUseProgram(program);
gles.glDeleteShader(vertexShader);
gles.glDeleteShader(fragmentShader);

let vao_list = gles.glGenVertexArrays(1);
let vao = vao_list[0];
gles.glBindVertexArray(vao);
gles.glBindBuffer(gles.GL_ARRAY_BUFFER, vbo);
gles.glBufferData(gles.GL_ARRAY_BUFFER, vertex_list, gles.GL_STATIC_DRAW);

gles.glVertexAttribPointer(0, 3, gles.GL_FLOAT, gles.GL_FALSE, 12, 0);
gles.glEnableVertexAttribArray(0);
gles.glUseProgram(program);

gles.glDrawArrays(gles.GL_TRIANGLES, 0, 3);

egl.eglSwapBuffers(display, surface);

```
![image](img.png)
