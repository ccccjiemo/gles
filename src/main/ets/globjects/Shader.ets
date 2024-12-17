import {
  glCompileShader,
  glCreateShader,
  glGetShaderInfoLog,
  glShaderSource,
  glGetShaderiv,
  glDeleteShader
} from "../GLES";
import { fileIo as fs } from "@kit.CoreFileKit";
import { ShaderParamName, ShaderType, GL_TRUE } from "../constant/Index";
import { glGetError } from "libgles.so";

export class Shader {
  private _id: number;
  private _infoLog: string;
  private _type: ShaderType;
  private _isCompiled: boolean;

  constructor(type: ShaderType) {
    this._id = glCreateShader(type);
    this._infoLog = '';
    this._type = type;
    this._isCompiled = false;
  }

  static fromUri(type: ShaderType, uri: string, encoding?: string): Shader {
    let source = fs.readTextSync(uri, { encoding });
    return Shader.fromString(type, source);
  }

  static fromString(type: ShaderType, source: string): Shader {
    let shader = new Shader(type);
    shader.setShaderSource(source);
    shader.compile();
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