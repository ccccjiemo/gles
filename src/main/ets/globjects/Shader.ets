import { fileIo as fs } from "@kit.CoreFileKit";
import { ShaderParamName, ShaderType, GL_TRUE } from "../constant/Index";
import { createShaderWithSource_, glCompileShader, glCreateShader,
  glDeleteShader,
  glGetError,
  glGetShaderInfoLog,
  glGetShaderiv,
  glShaderSource } from "libgles.so";

export class Shader {
  private _id: number;
  private _infoLog: string;
  private _type: ShaderType;
  private _isCompiled: boolean;

  constructor(type: ShaderType)

  constructor(type: ShaderType, notInit: boolean)

  constructor(type: ShaderType, notInit?: boolean) {
    this._id = notInit ? -1 : glCreateShader(type);
    this._infoLog = '';
    this._type = type;
    this._isCompiled = false;
  }

  static fromUri(type: ShaderType, uri: string, encoding?: string): Shader {
    let source = fs.readTextSync(uri, { encoding });
    return Shader.fromString(type, source);
  }

  static fromString(type: ShaderType, source: string): Shader {
    let shader = new Shader(type, true);
    let result = createShaderWithSource_(type, source);
    shader._id = result.handle;
    shader._isCompiled = result.status == GL_TRUE;
    shader._infoLog = result.log;
    return shader;
  }

  get id(): number {
    return this._id;
  }

  get infoLog(): string {
    return this._infoLog;
  }

  get shaderType(): ShaderType {
    return this._type;
  }

  get isCompiled(): boolean {
    return this._isCompiled;
  }

  setShaderSource(source: string): void {
    glShaderSource(this._id, source);
  }

  compile(): boolean {
    let result: boolean = false;
    glCompileShader(this._id);
    let status = glGetShaderiv(this._id, ShaderParamName.GL_COMPILE_STATUS);
    this._infoLog = glGetShaderInfoLog(this._id);
    this._isCompiled = status == GL_TRUE ? true : false;
    return result;
  }

  delete(): boolean {
    glDeleteShader(this._id);
    let err = glGetError();
    return glGetShaderiv(this._id, ShaderParamName.GL_DELETE_STATUS) == GL_TRUE;
  }
}

@Sendable
export class Shader2 {
  private _id: number;
  private _infoLog: string;
  private _type: number;
  private _isCompiled: boolean;

  constructor(type: ShaderType)

  constructor(type: ShaderType, notInit: boolean)

  constructor(type: ShaderType, notInit?: boolean) {
    this._id = notInit ? -1 : glCreateShader(type);
    this._infoLog = '';
    this._type = type;
    this._isCompiled = false;
  }

  static fromUri(type: ShaderType, uri: string, encoding?: string): Shader2 {
    let source = fs.readTextSync(uri, { encoding });
    return Shader2.fromString(type, source);
  }

  static fromString(type: ShaderType, source: string): Shader2 {
    let shader = new Shader2(type, true);
    let result = createShaderWithSource_(type, source);
    shader._id = result.handle;
    shader._isCompiled = result.status == GL_TRUE;
    shader._infoLog = result.log;
    return shader;
  }

  get id(): number {
    return this._id;
  }

  get infoLog(): string {
    return this._infoLog;
  }

  get shaderType(): ShaderType {
    return this._type;
  }

  get isCompiled(): boolean {
    return this._isCompiled;
  }

  setShaderSource(source: string): void {
    glShaderSource(this._id, source);
  }

  compile(): boolean {
    let result: boolean = false;
    glCompileShader(this._id);
    let status = glGetShaderiv(this._id, ShaderParamName.GL_COMPILE_STATUS);
    this._infoLog = glGetShaderInfoLog(this._id);
    this._isCompiled = status == GL_TRUE ? true : false;
    return result;
  }

  delete(): boolean {
    glDeleteShader(this._id);
    let err = glGetError();
    return glGetShaderiv(this._id, ShaderParamName.GL_DELETE_STATUS) == GL_TRUE;
  }
}

