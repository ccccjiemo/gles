import {
  GLActiveAttrib,
  glActiveShaderProgram,
  glActiveTexture,
  glAttachShader,
  glBeginQuery,
  glBeginTransformFeedback,
  glBindAttribLocation,
  glBindBuffer,
  glBindFramebuffer,
  glBindRenderbuffer,
  glBindTexture,
  glBindVertexArray,
  glBindVertexBuffer,
  glBlendColor,
  glBlendEquation,
  glBlendEquationi,
  glBlendEquationSeparate,
  glBlendFunc,
  glBlendFuncSeparate,
  glBlendFuncSeparatei,
  glBufferData,
  glBufferSubData,
  glCheckFramebufferStatus,
  glClear,
  glClearColor,
  glClearDepthf,
  glClearStencil,
  glColorMask,
  glCompileShader,
  glCompressedTexImage2D,
  glCopyTexImage2D,
  glCopyTexSubImage2D,
  glCreateProgram,
  glCreateShader,
  glCullFace,
  glDeleteBuffers,
  glDeleteFramebuffers,
  glDeleteProgram,
  glDeleteRenderbuffers,
  glDeleteShader,
  glDeleteTextures,
  glDeleteVertexArrays,
  glDepthFunc,
  glDepthMask,
  glDepthRangef,
  glDetachShader,
  glDisable,
  glDisableVertexAttribArray,
  glDrawArrays,
  glDrawElements,
  glEnable,
  glEnableVertexAttribArray,
  glEndQuery,
  glEndTransformFeedback,
  glFinish,
  glFlush,
  glFramebufferRenderbuffer,
  glFramebufferTexture2D,
  glFrontFace,
  glGenBuffers,
  glGenerateMipmap,
  glGenFramebuffers,
  glGenRenderbuffers,
  glGenTextures,
  glGenVertexArrays,
  glGetActiveAttrib,
  glGetActiveUniform,
  glGetAttachedShaders,
  glGetAttribLocation,
  glGetBooleanv,
  glGetBufferParameteri64v,
  glGetBufferParameteriv,
  glGetError,
  glGetFloatv,
  glGetFramebufferAttachmentParameteriv,
  glGetInteger64v,
  glGetIntegerv,
  glGetProgramInfoLog,
  glGetProgramiv,
  glGetRenderbufferParameteriv,
  glGetShaderInfoLog,
  glGetShaderPrecisionFormat,
  glGetShaderSource,
  glGetString,
  glGetTexParameterfv,
  glGetTexParameteriv,
  glGetUniformfv,
  glGetUniformiv,
  glGetUniformLocation,
  glGetVertexAttribfv,
  glGetVertexAttribiv,
  glGetVertexAttribPointerv,
  glHint,
  glIsBuffer,
  glIsEnabled,
  glIsFramebuffer,
  glIsRenderbuffer,
  glIsShader,
  glIsTexture,
  glLineWidth,
  glLinkProgram,
  glPixelStorei,
  glPolygonOffset,
  GLPrecision,
  glReadPixels,
  glReleaseShaderCompiler,
  glRenderbufferStorage,
  glSampleCoverage,
  glScissor,
  glShaderBinary,
  glShaderSource,
  glStencilFunc,
  glStencilFuncSeparate,
  glStencilMask,
  glStencilMaskSeparate,
  glStencilOp,
  glStencilOpSeparate,
  glTexImage2D,
  glTexParameterf,
  glTexParameterfv,
  glTexParameteri,
  glTexParameteriv,
  glTexSubImage2D,
  glUniform1f,
  glUniform1fv,
  glUniform1i,
  glUniform1iv,
  glUniform2f,
  glUniform2fv,
  glUniform2i,
  glUniform2iv,
  glUniform3f,
  glUniform3fv,
  glUniform3i,
  glUniform3iv,
  glUniform4f,
  glUniform4fv,
  glUniform4i,
  glUniform4iv,
  glUniformMatrix2fv,
  glUniformMatrix3fv,
  glUniformMatrix4fv,
  glUseProgram,
  glValidateProgram,
  glVertexAttrib1f,
  glVertexAttrib1fv,
  glVertexAttrib2f,
  glVertexAttrib2fv,
  glVertexAttrib3f,
  glVertexAttrib3fv,
  glVertexAttrib4f,
  glVertexAttribBinding,
  glVertexAttribFormat,
  glVertexAttribIFormat,
  glVertexAttribPointer,
  glViewport
} from "libgles.so";
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
} from "./constant/Index";
import { glGetShaderiv } from "./Index";

@Sendable
export class GL {
  glActiveShaderProgram(pipeline: number, program: number): void {
    glActiveShaderProgram(pipeline, program);
  }

  glActiveTexture(texture: GLTexture): void {
    glActiveTexture(texture);
  }

  glAttachShader(program: number, ...shader: number[]): void {
    glAttachShader(program, ...shader);
  }

  glBeginQuery(target: QueryTarget, id: number): void {
    glBeginQuery(target, id);
  }

  glEndQuery(target: QueryTarget): void {
    glEndQuery(target);
  }

  glBeginTransformFeedback(primitiveMode: PrimitiveMode): void {
    glBeginTransformFeedback(primitiveMode);
  }

  glEndTransformFeedback(): void {
    glEndTransformFeedback();
  }

  glBindAttribLocation(program: number, index: number, name: string): void {
    glBindAttribLocation(program, index, name);
  }

  glBindBuffer(target: BufferType, buffer: number): void {
    glBindBuffer(target, buffer);
  }

  glBindFramebuffer(target: FrameBufferTarget, framebuffer: number): void {
    glBindFramebuffer(target, framebuffer);
  }

  /***
   * @param target must be GL_RENDERBUFFER.
   */
  glBindRenderbuffer(target: RenderBufferTarget, renderbuffer: number): void {
    glBindRenderbuffer(target, renderbuffer);
  }

  glBindTexture(target: TextureTarget, texture: number): void {
    glBindTexture(target, texture);
  }

  glBlendColor(red: number, green: number, blue: number, alpha: number): void {
    glBlendColor(red, green, blue, alpha);
  }

  glBlendEquation(mode: BlendMode): void {
    glBlendEquation(mode);
  }

  glBlendEquationi(buffer: number, mode: BlendMode): void {
    glBlendEquationi(buffer, mode);
  }

  glBlendEquationSeparate(modeRGB: BlendMode, modeAlpha: BlendMode): void {
    glBlendEquationSeparate(modeRGB, modeAlpha);
  }

  glBlendFunc(sfactor: BlendingFactors, dfactor: BlendingFactors): void {
    glBlendFunc(sfactor, dfactor);
  }

  glBlendFuncSeparate(sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
    sfactorAlpha: BlendingFactors,
    dfactorAlpha: BlendingFactors): void {
    glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  }

  glBlendFuncSeparatei(buffer: number, sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
    sfactorAlpha: BlendingFactors,
    dfactorAlpha: BlendingFactors): void {
    glBlendFuncSeparatei(buffer, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
  }

  glBufferData(target: BufferType, data: ArrayLike<number>, usage: BufferUsage): void {
    glBufferData(target, data, usage);
  }

  glBufferSubData(target: BufferType, offset: number, data: ArrayLike<number>): void {
    glBufferSubData(target, offset, data);
  }

  glCheckFramebufferStatus(target: FrameBufferTarget): FrameBufferStatus {
    return glCheckFramebufferStatus(target);
  }

  glClear(mask: GLbitfield): void {
    glClear(mask);
  }

  glClearColor(red: number, green: number, blue: number, aplha: number): void {
    glClearColor(red, green, blue, aplha)
  }

  glClearDepthf(d: number): void {
    glClearDepthf(d)
  }

  glClearStencil(s: number): void {
    glClearStencil(s)
  }

  glColorMask(red: boolean, green: boolean, blue: boolean, alpha: boolean): void {
    glColorMask(red ? 1 : 0, green ? 1 : 0, blue ? 1 : 0, alpha ? 1 : 0);
  }

  glCompileShader(shader: number): void {
    glCompileShader(shader)
  }

  glCompressedTexImage2D(target: TexImage2DTarget, level: number,
    internalformat: CompressedInternalFormat,
    width: number, height: number, border: number, data: ArrayLike<number>): void {
    glCompressedTexImage2D(target, level, internalformat, width, height, border, data);
  }

  glCopyTexImage2D(target: TexImage2DTarget, level: number, internalformat: InternalFormat,
    x: number, y: number, width: number, height: number, border: number): void {
    glCopyTexImage2D(target, level, internalformat, x, y, width, height, border)
  }

  glCopyTexSubImage2D(target: TexImage2DTarget, level: number, xoffset: number, yoffset: number,
    x: number, y: number, width: number, height: number): void {
    glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height)
  }

  glCreateProgram(): number {
    return glCreateProgram();
  }

  glCreateShader(type: ShaderType): number {
    return glCreateShader(type);
  }

  glCullFace(mode: FaceMode): void {
    glCullFace(mode)
  }

  glDeleteBuffers(...buffers: number[]): void {
    glDeleteBuffers(new Uint32Array(buffers));
  }

  glDeleteVertexArrays(...arrays: number[]): void {
    glDeleteVertexArrays(new Uint32Array(arrays));
  }

  glDeleteFramebuffers(...buffers: number[]): void {
    glDeleteFramebuffers(new Uint32Array(buffers));
  }

  glDeleteProgram(program: number): void {
    glDeleteProgram(program)
  }

  glDeleteRenderbuffers(...buffers: number[]): void {
    glDeleteRenderbuffers(new Uint32Array(buffers));
  }

  glDeleteShader(shader: number): void {
    glDeleteShader(shader)
  }

  glDeleteTextures(...textures: number[]): void {
    glDeleteTextures(new Uint32Array(textures));
  }

  glDepthFunc(func: Func): void {
    glDepthFunc(func)
  }

  glDepthMask(flag: boolean): void {
    glDepthMask(flag ? 1 : 0);
  }

  glDepthRangef(n: number, f: number): void {
    glDepthRangef(n, f)
  }

  glDetachShader(program: number, shader: number): void {
    glDetachShader(program, shader)
  }

  glDisable(cap: GLCapability): void {
    glDisable(cap)
  }

  glDisableVertexAttribArray(index: number): void {
    glDisableVertexAttribArray(index)
  }

  glDrawArrays(mode: DrawMode, first: number, count: number): void {
    glDrawArrays(mode, first, count)
  }

  glDrawElements(mode: DrawMode, count: number, type: IndicesType, indices: ArrayLike<number>): void {
    glDrawElements(mode, count, type, indices);
  }

  glEnable(cap: GLCapability): void {
    glEnable(cap);
  }

  glEnableVertexAttribArray(index: number): void {
    glEnableVertexAttribArray(index)
  }

  glFinish(): void {
    glFinish()
  }

  glFlush(): void {
    glFlush()
  }

  glFramebufferRenderbuffer(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    renderbuffertarget: RenderBufferTarget, renderbuffer: number): void {
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  }

  glFramebufferTexture2D(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    textarget: TextureTarget,
    texture: number,
    level: number): void {
    glFramebufferTexture2D(target, attachment, textarget, texture, level)
  }

  glFrontFace(mode: FrontFaceMode): void {
    glFrontFace(mode)
  }

  glGenBuffers(n: number): Uint32Array {
    return glGenBuffers(n);
  }

  glGenVertexArrays(n: number): Uint32Array {
    return glGenVertexArrays(n)
  }

  /***
   * @param target not accept GL_TEXTURE_BUFFE,GL_TEXTURE_2D_MULTISAMPLE,GL_TEXTURE_2D_MULTISAMPLE_ARRAY
   */
  glGenerateMipmap(target: MipmapTarget): void {
    glGenerateMipmap(target)
  }

  glGenFramebuffers(n: number): Uint32Array {
    return glGenFramebuffers(n);
  }

  glGenRenderbuffers(n: number): Uint32Array {
    return glGenRenderbuffers(n);
  }

  glGenTextures(n: number): Uint32Array {
    return glGenTextures(n);
  }

  glGetActiveAttrib(program: number, index: number): GLActiveAttrib {
    return glGetActiveAttrib(program, index);
  }

  glGetActiveUniform(program: number, index: number): GLActiveAttrib {
    return glGetActiveUniform(program, index);
  }

  glGetAttachedShaders(program: number): Uint32Array {
    return glGetAttachedShaders(program)
  }

  glGetAttribLocation(program: number, name: string): number {
    return glGetAttribLocation(program, name);
  }

  glGetBufferParameteriv(target: BufferType, pname: BufferParamName): number {
    return glGetBufferParameteriv(target, pname);
  }

  glGetBufferParameteri64v(target: BufferType, pname: BufferParamName): number {
    return glGetBufferParameteri64v(target, pname);
  }

  glGetError(): GLError {
    return glGetError()
  }

  /***
   * @param pname enum ParamName
   * @param size buffer size
   */
  glGetFloatv(pname: ParamName, size: number): Float32Array {
    return glGetFloatv(pname, size);
  }

  /***
   * @param pname enum ParamName
   * @param size buffer size
   */
  glGetBooleanv(pname: ParamName, size: number): Uint8Array {
    return new Uint8Array(glGetBooleanv(pname, size));
  }

  /***
   * @param pname enum ParamName
   * @param size buffer size
   */
  glGetIntegerv(pname: ParamName, size: number): Int32Array {
    return glGetIntegerv(pname, size);
  }

  /***
   * @param pname enum ParamName
   * @param size buffer size
   */
  glGetInteger64v(pname: ParamName, size: number): BigInt64Array {
    return glGetInteger64v(pname, size);
  }

  glGetFramebufferAttachmentParameteriv(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    pname: FrameBufferAttachmentParamName): number {
    return glGetFramebufferAttachmentParameteriv(target, attachment, pname);
  }

  glGetProgramiv(program: number, pname: ProgramParamName): number {
    return glGetProgramiv(program, pname);
  }

  glGetProgramInfoLog(program: number): string {
    return glGetProgramInfoLog(program);
  }

  glGetRenderbufferParameteriv(target: RenderBufferTarget, pname: RenderBufferParamName): number {
    return glGetRenderbufferParameteriv(target, pname);
  }

  glGetShaderiv(shader: number, pname: ShaderParamName): number {
    return glGetShaderiv(shader, pname);
  }

  glGetShaderInfoLog(shader: number): string {
    return glGetShaderInfoLog(shader)
  }

  /***
   * shaderType must be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
   */
  glGetShaderPrecisionFormat(shadertype: ShaderType, precisiontype: PrecisionType): GLPrecision {
    return glGetShaderPrecisionFormat(shadertype, precisiontype)
  }

  glGetShaderSource(shader: number): string {
    return glGetShaderSource(shader)
  }

  glGetString(name: GetStringName): string {
    return glGetString(name)
  }


  glGetTexParameterfv(target: TextureTarget, pname: TexParamName): number {
    return glGetTexParameterfv(target, pname)
  }

  glGetTexParameteriv(target: TextureTarget, pname: TexParamName): number {
    return glGetTexParameteriv(target, pname)
  }

  glGetUniformfv(program: number, location: number): number {
    return glGetUniformfv(program, location);
  }

  glGetUniformiv(program: number, location: number): number {
    return glGetUniformiv(program, location)
  }

  glGetUniformLocation(program: number, name: string): number {
    return glGetUniformLocation(program, name);
  }

  glGetVertexAttribfv(index: number, pname: VertexAttribParamName): Float32Array {
    return glGetVertexAttribfv(index, pname)
  }

  glGetVertexAttribiv(index: number, pname: VertexAttribParamName): Int32Array {
    return glGetVertexAttribiv(index, pname);
  }

  /***
   * @deprecated 方法未实现
   */
  glGetVertexAttribPointerv(): void {
    glGetVertexAttribPointerv()
  }


  glHint(target: HintTarget, mode: HintMode): void {
    glHint(target, mode)
  }


  glIsBuffer(buffer: number): boolean {
    return Boolean(glIsBuffer(buffer));
  }

  glIsEnabled(cap: GLCapability): boolean {
    return Boolean(glIsEnabled(cap));
  }

  glIsFramebuffer(framebuffer: number): boolean {
    return Boolean(glIsFramebuffer(framebuffer));
  }

  glIsRenderbuffer(renderbuffer: number): boolean {
    return Boolean(glIsRenderbuffer(renderbuffer));
  }

  glIsShader(shader: number): boolean {
    return Boolean(glIsShader(shader));
  }

  glIsTexture(texture: number): boolean {
    return Boolean(glIsTexture(texture));
  }

  glLineWidth(width: number): void {
    glLineWidth(width)
  }


  glLinkProgram(program: number): void {
    glLinkProgram(program)
  }


  glPixelStorei(pname: PixelStorageMode, param: number): void {
    glPixelStorei(pname, param)
  }


  glPolygonOffset(factor: number, units: number): void {
    glPolygonOffset(factor, units)
  }


  glReadPixels(x: number, y: number, width: number, height: number, format: PixelFormat,
    type: IndicesType): ArrayBuffer {
    return glReadPixels(x, y, width, height, format, type);
  }

  glReleaseShaderCompiler(): void {
    glReleaseShaderCompiler()
  }


  glRenderbufferStorage(target: RenderBufferTarget, internalformat: InternalFormat, width: number,
    height: number): void {
    glRenderbufferStorage(target, internalformat, width, height);
  }

  glSampleCoverage(value: number, invert: boolean): void {
    glSampleCoverage(value, invert ? 1 : 0)
  }


  glScissor(x: number, y: number, width: number, height: number): void {
    glScissor(x, y, width, height)
  }


  /***
   * @deprecated 方法未实现
   */
  glShaderBinary(): void {
    glShaderBinary()
  }


  glShaderSource(shader: number, source: string): void {
    glShaderSource(shader, source)
  }


  glStencilFunc(func: Func, ref: number, mask: number): void {
    glStencilFunc(func, ref, mask)
  }


  glStencilFuncSeparate(face: FaceMode, func: Func, ref: number, mask: number): void {
    glStencilFuncSeparate(face, func, ref, mask);
  }

  glStencilMask(mask: number): void {
    glStencilMask(mask)
  }


  glStencilMaskSeparate(face: FaceMode, mask: number): void {
    glStencilMaskSeparate(face, mask)
  }


  glStencilOp(fail: TestFail, zfail: TestFail, zpass: TestFail): void {
    glStencilOp(fail, zfail, zpass)
  }


  glStencilOpSeparate(face: FaceMode, sfail: TestFail, dpfail: TestFail, dppass: TestFail): void {
    glStencilOpSeparate(face, sfail, dpfail, dppass);
  }

  glTexImage2D(target: TextureTarget, level: number, internalformat: number, width: number,
    height: number,
    border: number, format: InternalFormat, type: IndicesType, pixels?: ArrayLike<number>): void {
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  }


  glTexParameterf(target: TextureTarget, pname: TexParamName, param: number): void {
    glTexParameterf(target, pname, param);
  }

  glTexParameterfv(target: TextureTarget, pname: TexParamName, params: number[]): void {
    glTexParameterfv(target, pname, new Float32Array(params))
  }

  glTexParameteri(target: TextureTarget, pname: TexParamName, param: number): void {
    glTexParameteri(target, pname, param);
  }

  glTexParameteriv(target: TextureTarget, pname: TexParamName, params: number[]): void {
    glTexParameteriv(target, pname, new Int32Array(params))
  }

  glTexSubImage2D(target: TextureTarget, level: number, xoffset: number, yoffset: number, width: number,
    height: number, format: InternalFormat, type: IndicesType, pixels?: ArrayLike<number>): void {
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
  }

  glUniform1f(location: number, v0: number): void {
    glUniform1f(location, v0)
  }


  glUniform1fv(location: number, values: number[]): void {
    glUniform1fv(location, new Float32Array(values))
  }

  glUniform1i(location: number, v0: number): void {
    glUniform1i(location, v0)
  }


  glUniform1iv(location: number, values: number[]): void {
    glUniform1iv(location, new Uint32Array(values))
  }

  glUniform2f(location: number, v0: number, v1: number): void {
    glUniform2f(location, v0, v1)
  }


  glUniform2fv(location: number, values: number[]): void {
    glUniform2fv(location, new Float32Array(values))
  }

  glUniform2i(location: number, v0: number, v1: number): void {
    glUniform2i(location, v0, v1)
  }


  glUniform2iv(location: number, values: number[]): void {
    glUniform2iv(location, new Uint32Array(values))
  }

  glUniform3f(location: number, v0: number, v1: number, v2: number): void {
    glUniform3f(location, v0, v1, v2)
  }


  glUniform3fv(location: number, values: number[]): void {
    glUniform3fv(location, new Float32Array(values))
  }

  glUniform3i(location: number, v0: number, v1: number, v2: number): void {
    glUniform3i(location, v0, v1, v2)
  }


  glUniform3iv(location: number, values: number[]): void {
    glUniform3iv(location, new Uint32Array(values))
  }

  glUniform4f(location: number, v0: number, v1: number, v2: number, v3: number): void {
    glUniform4f(location, v0, v1, v2, v3)
  }

  glUniform4fv(location: number, values: number[]): void {
    glUniform4fv(location, new Float32Array(values))
  }

  glUniform4i(location: number, v0: number, v1: number, v2: number, v3: number): void {
    glUniform4i(location, v0, v1, v2, v3);
  }

  glUniform4iv(location: number, values: number[]): void {
    glUniform4iv(location, new Uint32Array(values))
  }

  glViewport(x: number, y: number, width: number, height: number): void {
    glViewport(x, y, width, height)
  }


  glVertexAttribPointer(index: number, size: number, type: IndicesType, normalized: boolean,
    stride: number,
    pointer: number): void {
    glVertexAttribPointer(index, size, type, normalized ? 1 : 0, stride, pointer);
  }


  glUniformMatrix2fv(location: number, count: number, transpose: boolean,
    value: number[]): void {
    glUniformMatrix2fv(location, count, transpose ? 1 : 0, new Float32Array(value))
  }

  glUniformMatrix3fv(location: number, count: number, transpose: boolean,
    value: number[]): void {
    glUniformMatrix3fv(location, count, transpose ? 1 : 0, new Float32Array(value))
  }

  glUniformMatrix4fv(location: number, count: number, transpose: boolean,
    value: number[]): void {
    glUniformMatrix4fv(location, count, transpose ? 1 : 0, new Float32Array(value))
  }

  glUseProgram(program: number): void {
    glUseProgram(program)
  }


  glValidateProgram(program: number): void {
    glValidateProgram(program)
  }


  glVertexAttrib1f(index: number, x: number): void {
    glVertexAttrib1f(index, x)
  }


  glVertexAttrib2f(index: number, x: number, y: number): void {
    glVertexAttrib2f(index, x, y)
  }


  glVertexAttrib3f(index: number, x: number, y: number, z: number): void {
    glVertexAttrib3f(index, x, y, z)
  }


  glVertexAttrib4f(index: number, x: number, y: number, z: number, w: number): void {
    glVertexAttrib4f(index, x, y, z, w);
  }

  glVertexAttrib1fv(index: number, v: number[]): void {
    glVertexAttrib1fv(index, new Float32Array(v))
  }

  glVertexAttrib2fv(index: number, v: number[]): void {
    glVertexAttrib2fv(index, new Float32Array(v))
  }

  glVertexAttrib3fv(index: number, v: number[]): void {
    glVertexAttrib3fv(index, new Float32Array(v))
  }

  glVertexAttrib4fv(index: number, v: number[]): void {
    glVertexAttrib3fv(index, new Float32Array(v))
  }

  glBindVertexArray(array: number): void {
    glBindVertexArray(array)
  }


  glBindVertexBuffer(bindingindex: number, buffer: number, offset: number, stride: number): void {
    glBindVertexBuffer(bindingindex, buffer, offset, stride);
  }

  glVertexAttribFormat(attribindex: number, size: number, type: IndicesType, normalized: boolean,
    relativeoffset: number): void {
    glVertexAttribFormat(attribindex, size, type, normalized ? 1 : 0, relativeoffset);
  }


  glVertexAttribIFormat(attribindex: number, size: number, type: IndicesType,
    relativeoffset: number): void {
    glVertexAttribIFormat(attribindex, size, type, relativeoffset);
  }

  glVertexAttribBinding(attribindex: number, bindingindex: number): void {
    glVertexAttribBinding(attribindex, bindingindex);
  }
}