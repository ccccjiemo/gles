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

type GLenum = number;


export function glActiveShaderProgram(pipeline: number, program: number): void;

export function glActiveTexture(texture: GLenum): void;

export function glAttachShader(program: number, ...shader: number[]): void;

export function glBeginQuery(target: GLenum, id: number): void;

export function glEndQuery(target: GLenum): void;

export function glBeginTransformFeedback(primitiveMode: GLenum): void;

export function glEndTransformFeedback(): void;

export function glBindAttribLocation(program: number, index: number, name: string): void;

export function glBindBuffer(target: GLenum, buffer: number): void;

export function glBindFramebuffer(target: GLenum, framebuffer: number): void;

export function glBindRenderbuffer(target: GLenum, renderbuffer: number): void;

export function glBindTexture(target: GLenum, texture: number): void;

export function glBlendColor(red: number, green: number, blue: number, alpha: number): void;

export function glBlendEquation(mode: GLenum): void;

export function glBlendEquationi(buffer: number, mode: GLenum): void

export function glBlendEquationSeparate(modeRGB: GLenum, modeAlpha: GLenum): void;

export function glBlendFunc(sfactor: GLenum, dfactor: GLenum): void;

export function glBlendFuncSeparate(sfactorRGB: GLenum, dfactorRGB: GLenum, sfactorAlpha: GLenum,
  dfactorAlpha: GLenum): void;

export const glBlendFuncSeparatei: (buffer: number, sfactorRGB: GLenum, dfactorRGB: GLenum, sfactorAlpha: GLenum,
  dfactorAlpha: GLenum) => void

export function glBufferData(target: GLenum, data: ArrayLike<number>, usage: GLenum): void;

export function glBufferSubData(target: GLenum, offset: number, data: ArrayLike<number>): void;

export function glCheckFramebufferStatus(target: GLenum): number;

// export function glCheckFramebufferStatus(target: GLenum): GLenum;

export function glClear(mask: number): void;

export function glClearColor(red: number, green: number, blue: number, aplha: number): void;

export function glClearDepthf(d: number): void;

export function glClearStencil(s: number): void;

export function glColorMask(red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean): void;

export function glCompileShader(shader: number): void;

export function glCompressedTexImage2D(target: GLenum, level: number, internalformat: GLenum, width: number,
  height: number, border: number, data: ArrayLike<number>): void;

export function glCompressedTexSubImage2D(target: GLenum, level: number, xoffset: number, yoffset: number,
  width: number,
  height: number, format: GLenum, data: ArrayBuffer): void;

export function glCopyTexImage2D(target: GLenum, level: number, internalformat: GLenum, x: number, y: number,
  width: number, height: number, border: number): void;

export function glCopyTexSubImage2D(target: GLenum, level: number, xoffset: number, yoffset: number, x: number,
  y: number,
  width: number, height: number): void;

export function glCreateProgram(): number;

export function glCreateShader(type: GLenum): number;

export function glCullFace(mode: GLenum): void;

export function glDeleteBuffers(buffers: Uint32Array): void;

export function glDeleteFramebuffers(buffers: Uint32Array): void;

export function glDeleteProgram(program: number): void;

export function glDeleteRenderbuffers(buffers: Uint32Array): void;

export function glDeleteShader(program: number): void;

export function glDeleteTextures(buffers: Uint32Array): void;

export function glDepthFunc(func: number): void;

export function glDepthMask(flag: GLboolean): void;

export function glDepthRangef(n: number, f: number): void;

export function glDetachShader(program: number, shader: number): void;

export function glDisable(cap: GLenum): void;

export function glDisableVertexAttribArray(index: number): void;

export function glDrawArrays(mode: GLenum, first: number, count: number): void;

export function glDrawElements(mode: GLenum, count: number, type: GLenum, indices: ArrayLike<number>): void;

export function glEnable(cap: GLenum): void;

export function glEnableVertexAttribArray(index: number): void;

export function glFinish(): void;

export function glFlush(): void;

export function glFramebufferRenderbuffer(target: GLenum, attachment: GLenum, renderbuffertarget: GLenum,
  renderbuffer: number): void;

export function glFramebufferTexture2D(target: GLenum, attachment: GLenum, textarget: GLenum, texture: number,
  level: number): void;

export function glFrontFace(mode: GLenum): void;

export function glGenBuffers(n: number): Uint32Array;

export function glGenVertexArrays(n: number): Uint32Array;


export function glGenerateMipmap(target: GLenum): void;

export function glGenFramebuffers(n: number): Uint32Array;

export function glGenRenderbuffers(n: number): Uint32Array;

export function glGenTextures(n: number): Uint32Array;

export function glGetActiveAttrib(program: number, index: number): GLActiveAttrib;

export function glGetActiveUniform(program: number, index: number): GLActiveAttrib;

export function glGetAttachedShaders(program: number): Uint32Array;

export function glGetAttribLocation(program: number, name: string): number;


export function glGetBufferParameteriv(target: GLenum, value: GLenum): number;

export function glGetBufferParameteri64v(target: GLenum, value: GLenum): number;

export function glGetError(): GLenum;

export function glGetFloatv(pname: GLenum, size: number): Float32Array;

export function glGetBooleanv(pname: GLenum, size: number): ArrayBuffer;

export function glGetIntegerv(pname: GLenum, size: number): Int32Array;

export function glGetInteger64v(pname: GLenum, size: number): BigInt64Array;

export function glGetFramebufferAttachmentParameteriv(target: GLenum, attachment: GLenum,
  pname: GLenum): number;

export function glGetProgramiv(program: number, pname: GLenum): number;

export function glGetProgramInfoLog(program: number): string;

export function glGetRenderbufferParameteriv(target: GLenum, pname: GLenum): number;

export function glGetShaderiv(shader: number, pname: GLenum): number;

export function glGetShaderInfoLog(shader: number): string;

export function glGetShaderPrecisionFormat(shadertype: GLenum, precisiontype: GLenum): GLPrecision;

export function glGetShaderSource(shader: number): string;

export function glGetString(name: GLenum): string;

export function glGetTexParameterfv(target: GLenum, pname: GLenum): number;

export function glGetTexParameteriv(target: GLenum, pname: GLenum): number;

export function glGetUniformfv(program: number, location: number): number;

export function glGetUniformiv(program: number, location: number): number;

export function glGetUniformLocation(program: number, name: string): number;

export function glGetVertexAttribfv(index: number, pname: GLenum): Float32Array;

export function glGetVertexAttribiv(index: number, pname: GLenum): Int32Array;

/**
 * @deprecated 方法未实现
 * */
export function glGetVertexAttribPointerv(): void;

export function glHint(target: GLenum, mode: GLenum): void;

export function glIsBuffer(buffer: number): GLboolean;

export function glIsEnabled(cap: GLenum): GLboolean;

export function glIsFramebuffer(framebuffer: number): GLboolean;

export function glIsRenderbuffer(renderbuffer: number): GLboolean;

export function glIsShader(shader: number): GLboolean;

export function glIsTexture(texture: number): GLboolean;

export function glLineWidth(width: number): void;

export function glLinkProgram(program: number): void;

export function glPixelStorei(pname: GLenum, param: number): void;

export function glPolygonOffset(factor: number, units: number): void;

export function glReadPixels(x: number, y: number, width: number, height: number, format: GLenum,
  type: GLenum): ArrayBuffer;

export function glReleaseShaderCompiler(): void;

export function glRenderbufferStorage(target: GLenum, internalformat: GLenum, width: number, height: number): void;

export function glSampleCoverage(value: number, invert: GLboolean): void;

export function glScissor(x: number, y: number, width: number, height: number): void;

/**
 * @description 方法未实现
 * */
export function glShaderBinary(): void;

export function glShaderSource(shader: number, source: string): void;

export function glStencilFunc(func: GLenum, ref: number, mask: number): void;

export function glStencilFuncSeparate(face: GLenum, func: GLenum, ref: number, mask: number): void;

export function glStencilMask(mask: number): void;

export function glStencilMaskSeparate(face: GLenum, mask: number): void;

export function glStencilOp(fail: GLenum, zfail: GLenum, zpass: GLenum): void;

export function glStencilOpSeparate(face: GLenum, sfail: GLenum, dpfail: GLenum, dppass: GLenum): void;

export function glTexImage2D(target: GLenum, level: number, internalformat: number, width: number, height: number,
  border: number, format: GLenum, type: GLenum, pixels?: ArrayLike<number>): void;

export function glTexParameterf(target: GLenum, pname: GLenum, param: number): void;

export function glTexParameterfv(target: GLenum, pname: GLenum, params: Float32Array): void;

export function glTexParameteri(target: GLenum, pname: GLenum, param: number): void;

export function glTexParameteriv(target: GLenum, pname: GLenum, params: Int32Array): void;

export function glTexSubImage2D(target: GLenum, level: number, xoffset: number, yoffset: number, width: number,
  height: number, format: GLenum, type: GLenum, pixels?: ArrayLike<number>): void;

export function glUniform1f(location: number, v0: number): void;

export function glUniform1fv(location: number, values: Float32Array): void;

export function glUniform1i(location: number, v0: number): void;

export function glUniform1iv(location: number, values: Uint32Array): void;

export function glUniform2f(location: number, v0: number, v1: number): void;

export function glUniform2fv(location: number, values: Float32Array): void;

export function glUniform2i(location: number, v0: number, v1: number): void;

export function glUniform2iv(location: number, values: Uint32Array): void;

export function glUniform3f(location: number, v0: number, v1: number, v2: number): void;

export function glUniform3fv(location: number, values: Float32Array): void;

export function glUniform3i(location: number, v0: number, v1: number, v2: number): void;

export function glUniform3iv(location: number, values: Uint32Array): void;

export function glUniform4f(location: number, v0: number, v1: number, v2: number, v3: number): void;

export function glUniform4fv(location: number, values: Float32Array): void;

export function glUniform4i(location: number, v0: number, v1: number, v2: number, v3: number): void;

export function glUniform4iv(location: number, values: Uint32Array): void;

export function glViewport(x: number, y: number, width: number, height: number): void;

export function glVertexAttribPointer(index: number, size: number, type: GLenum, normalized: GLboolean, stride: number,
  pointer: number): void;

export function glUniformMatrix2fv(location: number, count: number, transpose: GLboolean, value: Float32Array): void;

export function glUniformMatrix3fv(location: number, count: number, transpose: GLboolean, value: Float32Array): void;

export function glUniformMatrix4fv(location: number, count: number, transpose: GLboolean, value: Float32Array): void;

export function glUseProgram(program: number): void;

export function glValidateProgram(program: number): void;

export function glVertexAttrib1f(index: number, x: number): void;

export function glVertexAttrib2f(index: number, x: number, y: number): void;

export function glVertexAttrib3f(index: number, x: number, y: number, z: number): void;

export function glVertexAttrib4f(index: number, x: number, y: number, z: number, w: number): void;

export function glVertexAttrib1fv(index: number, v: Float32Array): void;

export function glVertexAttrib2fv(index: number, v: Float32Array): void;

export function glVertexAttrib3fv(index: number, v: Float32Array): void;

export function glVertexAttrib4fv(index: number, v: Float32Array): void;

export function glBindVertexArray(array: number): void;

/***
 * @param bindingindex GLuint
 * @param buffer GLuint
 * @param offset GLintptr
 * @param stride GLsizei
 */
export function glBindVertexBuffer(bindingindex: number, buffer: number, offset: number, stride: number): void;

export function glDeleteVertexArrays(arrays: Uint32Array): void;

export function glVertexAttribFormat(attribindex: number, size: number, type: number, normalized: number,
  relativeoffset: number): void;

export function glVertexAttribIFormat(attribindex: number, size: number, type: number, relativeoffset: number): void

export function glVertexAttribBinding(attribindex: number, bindingindex: number): void;

export function glMapBufferRange(target: number, offset: number, length: number, access: number): ArrayBuffer;

export function glUnmapBuffer(target: number): boolean;


//extends
interface GeneratedTypeLiteralInterface_1 {
  handle: number;
  status: number;
  log: string;
}

export function createShaderWithSource(type: number, source: string): GeneratedTypeLiteralInterface_1

interface GeneratedTypeLiteralInterface_2 {
  pname: number;
  param: number;
}

export function glTexParameteriGroup(texture: number, target: number,
  group: Array<GeneratedTypeLiteralInterface_2>): void;


@Sendable
export class NativeImage {
  constructor(texture?: number)

  get surfaceId(): string

  // get isAvailable(): number

  attachContext(texture: number): number

  detachContext(): number

  updateSurfaceImage(): number

  destroy(): void

  setOnFrameAvailableListener(callback: Function): number

  unSetOnFrameAvailableListener(): number
}

