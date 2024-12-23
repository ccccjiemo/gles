import * as GLESBase from 'libgles.so'
import {
  BlendingFactors,
  BufferParamName,
  BufferType,
  BufferUsage,
  CompressedInternalFormat,
  DrawMode,
  FaceMode,
  FrameBufferAttachment,
  FrameBufferAttachmentParamName,
  FrameBufferStatus,
  FrameBufferTarget,
  FrontFaceMode,
  Func,
  GetStringName,
  GLbitfield,
  GLCapability,
  GLError,
  GLTexture,
  HintMode,
  HintTarget,
  IndicesType,
  InternalFormat,
  MipmapTarget,
  ParamName,
  PixelFormat,
  PixelStorageMode,
  PrecisionType,
  PrimitiveMode,
  ProgramParamName,
  QueryTarget,
  RenderBufferParamName,
  RenderBufferTarget,
  ShaderParamName,
  ShaderType,
  TestFail,
  TexImage2DTarget,
  TexParamName,
  TextureTarget,
  VertexAttribParamName
} from './constant/Index'

export type GLboolean = 0 | 1;

export interface GLActiveAttrib {
  name: string;
  type: number;
  size: number;
}

export interface GLPrecision {
  range: number;
  precision: number;
}


export const glActiveShaderProgram: (pipeline: number, program: number) => void = GLESBase.glActiveShaderProgram;

export const glActiveTexture: (texture: GLTexture) => void = GLESBase.glActiveTexture;

export const glAttachShader: (program: number, ...shader: number[]) => void = GLESBase.glAttachShader;

export const glBeginQuery: (target: QueryTarget, id: number) => void = GLESBase.glBeginQuery;

export const glEndQuery: (target: QueryTarget) => void = GLESBase.glEndQuery;

export const glBeginTransformFeedback: (primitiveMode: PrimitiveMode) => void =
  GLESBase.glBeginTransformFeedback;

export const glEndTransformFeedback: () => void = GLESBase.glEndTransformFeedback;

export const glBindAttribLocation: (program: number, index: number, name: string) => void =
  GLESBase.glBindAttribLocation;

export const glBindBuffer: (target: BufferType, buffer: number) => void = GLESBase.glBindBuffer;

export const glBindFramebuffer: (target: FrameBufferTarget, framebuffer: number) => void = GLESBase.glBindFramebuffer;

/***
 * @param target must be GL_RENDERBUFFER.
 */
export const glBindRenderbuffer: (target: RenderBufferTarget, renderbuffer: number) => void =
  GLESBase.glBindRenderbuffer;

export const glBindTexture: (target: TextureTarget, texture: number) => void = GLESBase.glBindTexture;

export const glBlendColor: (red: number, green: number, blue: number, alpha: number) => void = GLESBase.glBlendColor;

export const glBlendEquation: (mode: BlendMode) => void = GLESBase.glBlendEquation;

export const glBlendEquationi: (buffer: number, mode: BlendMode) => void = GLESBase.glBlendEquationi;

export const glBlendEquationSeparate: (modeRGB: BlendMode, modeAlpha: BlendMode) => void =
  GLESBase.glBlendEquationSeparate;

export const glBlendFunc: (sfactor: BlendingFactors, dfactor: BlendingFactors) => void = GLESBase.glBlendFunc;

export const glBlendFuncSeparate: (sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
  sfactorAlpha: BlendingFactors,
  dfactorAlpha: BlendingFactors) => void = GLESBase.glBlendFuncSeparate;

export const glBlendFuncSeparatei: (buffer: number, sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
  sfactorAlpha: BlendingFactors,
  dfactorAlpha: BlendingFactors) => void = GLESBase.glBlendFuncSeparatei;

export const glBufferData: (target: BufferType, data: ArrayLike<number>, usage: BufferUsage) => void =
  GLESBase.glBufferData;

export const glBufferSubData: (target: BufferType, offset: number, data: ArrayLike<number>) => void =
  GLESBase.glBufferSubData;

export const glCheckFramebufferStatus: (target: FrameBufferTarget) => FrameBufferStatus =
  GLESBase.glCheckFramebufferStatus;

export const glClear: (mask: GLbitfield) => void = GLESBase.glClear;

export const glClearColor: (red: number, green: number, blue: number, aplha: number) => void = GLESBase.glClearColor;

export const glClearDepthf: (d: number) => void = GLESBase.glClearDepthf;

export const glClearStencil: (s: number) => void = GLESBase.glClearStencil;

export const glColorMask: (red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean) => void =
  GLESBase.glColorMask;

export const glCompileShader: (shader: number) => void = GLESBase.glCompileShader;

export const glCompressedTexImage2D: (target: TexImage2DTarget, level: number,
  internalformat: CompressedInternalFormat,
  width: number, height: number, border: number, data: ArrayLike<number>) => void = GLESBase.glCompressedTexImage2D;

export const glCompressedTexSubImage2D: (target: TexImage2DTarget, level: number, xoffset: number, yoffset: number,
  width: number, height: number, format: CompressedInternalFormat, data: ArrayBufferLike) => void =
  GLESBase.glCompressedTexSubImage2D;

export const glCopyTexImage2D: (target: TexImage2DTarget, level: number, internalformat: InternalFormat,
  x: number, y: number,
  width: number, height: number, border: number) => void = GLESBase.glCopyTexImage2D;

export const glCopyTexSubImage2D: (target: TexImage2DTarget, level: number, xoffset: number, yoffset: number,
  x: number,
  y: number, width: number, height: number) => void = GLESBase.glCopyTexSubImage2D;

export const glCreateProgram: () => number = GLESBase.glCreateProgram;

export const glCreateShader: (type: ShaderType) => number = GLESBase.glCreateShader;

export const glCullFace: (mode: FaceMode) => void = GLESBase.glCullFace;

export const glDeleteBuffers: (...buffers: number[]) => void = (...buffers: number[]) => {
  GLESBase.glDeleteBuffers(new Uint32Array(buffers));
}

export const glDeleteVertexArrays: (...arrays: number[]) => void = (...arrays: number[]) => {
  GLESBase.glDeleteVertexArrays(new Uint32Array(arrays));
}

export const glDeleteFramebuffers: (...buffers: number[]) => void = (...buffers: number[]) => {
  GLESBase.glDeleteFramebuffers(new Uint32Array(buffers));
}

export const glDeleteProgram: (program: number) => void = GLESBase.glDeleteProgram;

export const glDeleteRenderbuffers: (...buffers: number[]) => void = (...buffers: number[]) => {
  GLESBase.glDeleteRenderbuffers(new Uint32Array(buffers));
}

export const glDeleteShader: (shader: number) => void = GLESBase.glDeleteShader;

export const glDeleteTextures: (...textures: number[]) => void = (...textures: number[]) => {
  GLESBase.glDeleteTextures(new Uint32Array(textures));
}

export const glDepthFunc: (func: Func) => void = GLESBase.glDepthFunc;

export const glDepthMask: (flag: GLboolean) => void = GLESBase.glDepthMask;

export const glDepthRangef: (n: number, f: number) => void = GLESBase.glDepthRangef;

export const glDetachShader: (program: number, shader: number) => void = GLESBase.glDetachShader;

export const glDisable: (cap: GLCapability) => void = GLESBase.glDisable;

export const glDisableVertexAttribArray: (index: number) => void = GLESBase.glDisableVertexAttribArray;

export const glDrawArrays: (mode: DrawMode, first: number, count: number) => void = GLESBase.glDrawArrays;

export const glDrawElements: (mode: DrawMode, count: number, type: IndicesType, indices: ArrayLike<number>) => void =
  GLESBase.glDrawElements;

export const glEnable: (cap: GLCapability) => void = GLESBase.glEnable;

export const glEnableVertexAttribArray: (index: number) => void = GLESBase.glEnableVertexAttribArray;

export const glFinish: () => void = GLESBase.glFinish;

export const glFlush: () => void = GLESBase.glFlush;

export const glFramebufferRenderbuffer: (target: FrameBufferTarget, attachment: FrameBufferAttachment,
  renderbuffertarget: RenderBufferTarget,
  renderbuffer: number) => void = GLESBase.glFramebufferRenderbuffer;

export const glFramebufferTexture2D: (target: FrameBufferTarget, attachment: FrameBufferAttachment,
  textarget: TextureTarget,
  texture: number,
  level: number) => void = GLESBase.glFramebufferTexture2D;

export const glFrontFace: (mode: FrontFaceMode) => void = GLESBase.glFrontFace;

export const glGenBuffers: (n: number) => Uint32Array = GLESBase.glGenBuffers;

export const glGenVertexArrays: (n: number) => Uint32Array = GLESBase.glGenVertexArrays;

/***
 * @param target not accept GL_TEXTURE_BUFFE,GL_TEXTURE_2D_MULTISAMPLE,GL_TEXTURE_2D_MULTISAMPLE_ARRAY
 */
export const glGenerateMipmap: (target: MipmapTarget) => void = GLESBase.glGenerateMipmap;

export const glGenFramebuffers: (n: number) => Uint32Array = GLESBase.glGenFramebuffers;

export const glGenRenderbuffers: (n: number) => Uint32Array = GLESBase.glGenRenderbuffers;

export const glGenTextures: (n: number) => Uint32Array = GLESBase.glGenTextures;

export const glGetActiveAttrib: (program: number, index: number) => GLActiveAttrib = GLESBase.glGetActiveAttrib;

export const glGetActiveUniform: (program: number, index: number) => GLActiveAttrib = GLESBase.glGetActiveUniform;

export const glGetAttachedShaders: (program: number) => Uint32Array = GLESBase.glGetAttachedShaders;

export const glGetAttribLocation: (program: number, name: string) => number = GLESBase.glGetAttribLocation;

export const glGetBufferParameteriv: (target: BufferType, pname: BufferParamName) => number =
  GLESBase.glGetBufferParameteriv;

export const glGetBufferParameteri64v: (target: BufferType, value: BufferParamName) => number =
  GLESBase.glGetBufferParameteri64v;

export const glGetError: () => GLError = GLESBase.glGetError;

/***
 * @param pname enum ParamName
 * @param size buffer size
 */
export const glGetFloatv: (pname: ParamName, size: number) => Float32Array = GLESBase.glGetFloatv;

/***
 * @param pname enum ParamName
 * @param size buffer size
 */
export const glGetBooleanv: (pname: ParamName, size: number) => ArrayBuffer = GLESBase.glGetBooleanv;

/***
 * @param pname enum ParamName
 * @param size buffer size
 */
export const glGetIntegerv: (pname: ParamName, size: number) => Int32Array = GLESBase.glGetIntegerv;

/***
 * @param pname enum ParamName
 * @param size buffer size
 */
export const glGetInteger64v: (pname: ParamName, size: number) => BigInt64Array = GLESBase.glGetInteger64v;

export const glGetFramebufferAttachmentParameteriv: (target: FrameBufferTarget, attachment: FrameBufferAttachment,
  pname: FrameBufferAttachmentParamName) => number =
  GLESBase.glGetFramebufferAttachmentParameteriv;

export const glGetProgramiv: (program: number, pname: ProgramParamName) => number = GLESBase.glGetProgramiv;

export const glGetProgramInfoLog: (program: number) => string = GLESBase.glGetProgramInfoLog;

export const glGetRenderbufferParameteriv: (target: RenderBufferTarget, pname: RenderBufferParamName) => number =
  GLESBase.glGetRenderbufferParameteriv;

export const glGetShaderiv: (shader: number, pname: ShaderParamName) => number = GLESBase.glGetShaderiv;

export const glGetShaderInfoLog: (shader: number) => string = GLESBase.glGetShaderInfoLog;

/***
 * shaderType must be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
 */
export const glGetShaderPrecisionFormat: (shadertype: ShaderType, precisiontype: PrecisionType) => GLPrecision =
  GLESBase.glGetShaderPrecisionFormat;

export const glGetShaderSource: (shader: number) => string = GLESBase.glGetShaderSource;


export const glGetString: (name: GetStringName) => string = GLESBase.glGetString;

export const glGetTexParameterfv: (target: TextureTarget, pname: TexParamName) => number =
  GLESBase.glGetTexParameterfv;

export const glGetTexParameteriv: (target: TextureTarget, pname: TexParamName) => number =
  GLESBase.glGetTexParameteriv;

export const glGetUniformfv: (program: number, location: number) => number = GLESBase.glGetUniformfv;

export const glGetUniformiv: (program: number, location: number) => number = GLESBase.glGetUniformiv;

export const glGetUniformLocation: (program: number, name: string) => number = GLESBase.glGetUniformLocation;

export const glGetVertexAttribfv: (index: number, pname: VertexAttribParamName) => Float32Array =
  GLESBase.glGetVertexAttribfv;

export const glGetVertexAttribiv: (index: number, pname: VertexAttribParamName) => Int32Array =
  GLESBase.glGetVertexAttribiv;

/***
 * @deprecated 方法未实现
 */
export const glGetVertexAttribPointerv: () => void = GLESBase.glGetVertexAttribPointerv;

export const glHint: (target: HintTarget, mode: HintMode) => void = GLESBase.glHint;

export const glIsBuffer: (buffer: number) => GLboolean = GLESBase.glIsBuffer;

export const glIsEnabled: (cap: GLCapability) => GLboolean = GLESBase.glIsEnabled;

export const glIsFramebuffer: (framebuffer: number) => GLboolean = GLESBase.glIsFramebuffer;

export const glIsRenderbuffer: (renderbuffer: number) => GLboolean = GLESBase.glIsRenderbuffer;

export const glIsShader: (shader: number) => GLboolean = GLESBase.glIsShader;

export const glIsTexture: (texture: number) => GLboolean = GLESBase.glIsTexture;

export const glLineWidth: (width: number) => void = GLESBase.glLineWidth;

export const glLinkProgram: (program: number) => void = GLESBase.glLinkProgram;

export const glPixelStorei: (pname: PixelStorageMode, param: number) => void = GLESBase.glPixelStorei;

export const glPolygonOffset: (factor: number, units: number) => void = GLESBase.glPolygonOffset;

export const glReadPixels: (x: number, y: number, width: number, height: number, format: PixelFormat,
  type: IndicesType) => ArrayBuffer = GLESBase.glReadPixels;

export const glReleaseShaderCompiler: () => void = GLESBase.glReleaseShaderCompiler;

export const glRenderbufferStorage: (target: RenderBufferTarget, internalformat: InternalFormat, width: number,
  height: number) => void =
  GLESBase.glRenderbufferStorage;

export const glSampleCoverage: (value: number, invert: GLboolean) => void = GLESBase.glSampleCoverage;

export const glScissor: (x: number, y: number, width: number, height: number) => void = GLESBase.glScissor;

/***
 * @deprecated 方法未实现
 */
export const glShaderBinary: () => void = GLESBase.glShaderBinary;

export const glShaderSource: (shader: number, source: string) => void = GLESBase.glShaderSource;

export const glStencilFunc: (func: Func, ref: number, mask: number) => void = GLESBase.glStencilFunc;

export const glStencilFuncSeparate: (face: FaceMode, func: Func, ref: number, mask: number) => void =
  GLESBase.glStencilFuncSeparate;

export const glStencilMask: (mask: number) => void = GLESBase.glStencilMask;

export const glStencilMaskSeparate: (face: FaceMode, mask: number) => void = GLESBase.glStencilMaskSeparate;

export const glStencilOp: (fail: TestFail, zfail: TestFail, zpass: TestFail) => void = GLESBase.glStencilOp;

export const glStencilOpSeparate: (face: FaceMode, sfail: TestFail, dpfail: TestFail, dppass: TestFail) => void =
  GLESBase.glStencilOpSeparate;

export const glTexImage2D: (target: TextureTarget, level: number, internalformat: number, width: number,
  height: number,
  border: number, format: InternalFormat, type: IndicesType, pixels?: ArrayLike<number>) => void =
  GLESBase.glTexImage2D;

export const glTexParameterf: (target: TextureTarget, pname: TexParamName, param: number) => void =
  GLESBase.glTexParameterf;

export const glTexParameterfv: (target: TextureTarget, pname: TexParamName, params: number[]) => void =
  (target, pname, params) => {
    GLESBase.glTexParameterfv(target, pname, new Float32Array(params));
  }

export const glTexParameteri: (target: TextureTarget, pname: TexParamName, param: number) => void =
  GLESBase.glTexParameteri;

export const glTexParameteriv: (target: TextureTarget, pname: TexParamName, params: number[]) => void =
  (target, pname, params) => {
    GLESBase.glTexParameteriv(target, pname, new Int32Array(params));
  }

export const glTexSubImage2D: (target: TextureTarget, level: number, xoffset: number, yoffset: number, width: number,
  height: number, format: InternalFormat, type: IndicesType, pixels?: ArrayLike<number>) => void =
  GLESBase.glTexSubImage2D;

export const glUniform1f: (location: number, v0: number) => void = GLESBase.glUniform1f;

export const glUniform1fv: (location: number, values: number[]) => void = (l, v) => {
  GLESBase.glUniform1fv(l, new Float32Array(v));
}

export const glUniform1i: (location: number, v0: number) => void = GLESBase.glUniform1i;

export const glUniform1iv: (location: number, values: number[]) => void = (l, v) => {
  GLESBase.glUniform1iv(l, new Uint32Array(v));
}

export const glUniform2f: (location: number, v0: number, v1: number) => void = GLESBase.glUniform2f;

export const glUniform2fv: (location: number, values: number[]) => void = (l, v) => {
  GLESBase.glUniform2fv(l, new Float32Array(v));
}

export const glUniform2i: (location: number, v0: number, v1: number) => void = GLESBase.glUniform2i;

export const glUniform2iv: (location: number, values: number[]) => void = (location, values) => {
  GLESBase.glUniform2iv(location, new Uint32Array(values));
}

export const glUniform3f: (location: number, v0: number, v1: number, v2: number) => void = GLESBase.glUniform3f;

export const glUniform3fv: (location: number, values: number[]) => void = (location, values) => {
  GLESBase.glUniform3fv(location, new Float32Array(values));
}

export const glUniform3i: (location: number, v0: number, v1: number, v2: number) => void = GLESBase.glUniform3i;

export const glUniform3iv: (location: number, values: number[]) => void = (location, values) => {
  GLESBase.glUniform3iv(location, new Uint32Array(values));
}

export const glUniform4f: (location: number, v0: number, v1: number, v2: number, v3: number) => void =
  GLESBase.glUniform4f;

export const glUniform4fv: (location: number, values: number[]) => void = (location: number, values: number[]) => {
  GLESBase.glUniform4fv(location, new Float32Array(values));
}

export const glUniform4i: (location: number, v0: number, v1: number, v2: number, v3: number) => void =
  GLESBase.glUniform4i;

export const glUniform4iv: (location: number, values: number[]) => void = (location: number, values: number[]) => {
  GLESBase.glUniform4iv(location, new Uint32Array(values));
}

export const glViewport: (x: number, y: number, width: number, height: number) => void = GLESBase.glViewport;

export const glVertexAttribPointer: (index: number, size: number, type: IndicesType, normalized: GLboolean,
  stride: number,
  pointer: number) => void = GLESBase.glVertexAttribPointer;

export const glUniformMatrix2fv: (location: number, count: number, transpose: GLboolean,
  value: number[]) => void = (l, c, t, v) => {
  GLESBase.glUniformMatrix2fv(l, c, t, new Float32Array(v));
}

export const glUniformMatrix3fv: (location: number, count: number, transpose: GLboolean,
  value: number[]) => void = (l, c, t, v) => {
  GLESBase.glUniformMatrix3fv(l, c, t, new Float32Array(v));
}

export const glUniformMatrix4fv: (location: number, count: number, transpose: GLboolean,
  value: number[]) => void = (l, c, t, v) => {
  GLESBase.glUniformMatrix4fv(l, c, t, new Float32Array(v));
}

export const glUseProgram: (program: number) => void = GLESBase.glUseProgram;

export const glValidateProgram: (program: number) => void = GLESBase.glValidateProgram;

export const glVertexAttrib1f: (index: number, x: number) => void = GLESBase.glVertexAttrib1f;

export const glVertexAttrib2f: (index: number, x: number, y: number) => void = GLESBase.glVertexAttrib2f;

export const glVertexAttrib3f: (index: number, x: number, y: number, z: number) => void = GLESBase.glVertexAttrib3f;

export const glVertexAttrib4f: (index: number, x: number, y: number, z: number, w: number) => void =
  GLESBase.glVertexAttrib4f;

export const glVertexAttrib1fv: (index: number, v: number[]) => void = (i, v) => {
  GLESBase.glVertexAttrib1fv(i, new Float32Array(v));
}

export const glVertexAttrib2fv: (index: number, v: number[]) => void = (i, v) => {
  GLESBase.glVertexAttrib2fv(i, new Float32Array(v));
}

export const glVertexAttrib3fv: (index: number, v: number[]) => void = (i, v) => {
  GLESBase.glVertexAttrib3fv(i, new Float32Array(v));
}

export const glVertexAttrib4fv: (index: number, v: number[]) => void = (i, v) => {
  GLESBase.glVertexAttrib3fv(i, new Float32Array(v));
}

export const glBindVertexArray: (array: number) => void = GLESBase.glBindVertexArray;

export const glBindVertexBuffer: (bindingindex: number, buffer: number, offset: number, stride: number) => void =
  GLESBase.glBindVertexBuffer;

export const glVertexAttribFormat: (attribindex: number, size: number, type: IndicesType, normalized: number,
  relativeoffset: number) => void = GLESBase.glVertexAttribFormat;

export const glVertexAttribIFormat: (attribindex: number, size: number, type: IndicesType,
  relativeoffset: number) => void =
  GLESBase.glVertexAttribIFormat;

export const glVertexAttribBinding: (attribindex: number, bindingindex: number) => void =
  GLESBase.glVertexAttribBinding;
