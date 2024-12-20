export namespace gles {
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

  export enum GLTexture {
    GL_TEXTURE0, GL_TEXTURE1, GL_TEXTURE2, GL_TEXTURE3,
    GL_TEXTURE4, GL_TEXTURE5, GL_TEXTURE6, GL_TEXTURE7,
    GL_TEXTURE8, GL_TEXTURE9, GL_TEXTURE10, GL_TEXTURE11,
    GL_TEXTURE12, GL_TEXTURE13, GL_TEXTURE14, GL_TEXTURE15,
    GL_TEXTURE16, GL_TEXTURE17, GL_TEXTURE18, GL_TEXTURE19,
    GL_TEXTURE20, GL_TEXTURE21, GL_TEXTURE22, GL_TEXTURE23,
    GL_TEXTURE24, GL_TEXTURE25, GL_TEXTURE26, GL_TEXTURE27,
    GL_TEXTURE28, GL_TEXTURE29, GL_TEXTURE30, GL_TEXTURE31,
  }

  export enum QueryTarget {
    GL_ANY_SAMPLES_PASSED, GL_ANY_SAMPLES_PASSED_CONSERVATIVE, GL_PRIMITIVES_GENERATED, GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
  }

  export enum PrimitiveMode {
    GL_POINTS, GL_LINES, GL_TRIANGLES = 0x0004
  }

  export enum BlendingFactors {
    GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR,
    GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_CONSTANT_COLOR,
    GL_ONE_MINUS_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA, GL_SRC_ALPHA_SATURATE
  }

  export enum BlendMode {
    GL_FUNC_ADD,
    GL_FUNC_SUBTRACT,
    GL_FUNC_REVERSE_SUBTRACT,
    GL_MIN,
    GL_MAX
  }

  export enum BufferParamName {
    GL_BUFFER_ACCESS_FLAGS = 0x911F,
    GL_BUFFER_MAPPED = 0x88BC,
    GL_BUFFER_MAP_LENGTH = 0x9120,
    GL_BUFFER_MAP_OFFSET = 0x9121,
    GL_BUFFER_SIZE = 0x8764,
    GL_BUFFER_USAGE = 0x8765,
  }

  export enum BufferType {
    GL_ARRAY_BUFFER = 0x8892,
    GL_ATOMIC_COUNTER_BUFFER = 0x92C0,
    GL_COPY_READ_BUFFER = 0x8F36,
    GL_COPY_WRITE_BUFFER = 0x8F37,
    GL_DISPATCH_INDIRECT_BUFFER = 0x90EE,
    GL_DRAW_INDIRECT_BUFFER = 0x8F3F,
    GL_ELEMENT_ARRAY_BUFFER = 0x8893,
    GL_PIXEL_PACK_BUFFER = 0x88EB,
    GL_PIXEL_UNPACK_BUFFER = 0x88EC,
    GL_SHADER_STORAGE_BUFFER = 0x90D2,
    GL_TEXTURE_BUFFER = 0x8C2A,
    GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,
    GL_UNIFORM_BUFFER = 0x8A11
  }

  export enum BufferUsage {
    GL_STREAM_DRAW = 0x88E0,
    GL_STREAM_READ = 0x88E1,
    GL_STREAM_COPY = 0x88E2,
    GL_STATIC_DRAW = 0x88E4,
    GL_STATIC_READ = 0x88E5,
    GL_STATIC_COPY = 0x88E6,
    GL_DYNAMIC_DRAW = 0x88E8,
    GL_DYNAMIC_READ = 0x88E9,
    GL_DYNAMIC_COPY = 0x88EA
  }

  export enum CompressedInternalFormat {
    GL_COMPRESSED_R11_EAC = 0x9270,
    GL_COMPRESSED_SIGNED_R11_EAC = 0x9271,
    GL_COMPRESSED_RG11_EAC = 0x9272,
    GL_COMPRESSED_SIGNED_RG11_EAC = 0x9273,
    GL_COMPRESSED_RGB8_ETC2 = 0x9274,
    GL_COMPRESSED_SRGB8_ETC2 = 0x9275,
    GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276,
    GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277,
    GL_COMPRESSED_RGBA8_ETC2_EAC = 0x9278,
    GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279,
    GL_COMPRESSED_RGBA_ASTC_4x4 = 0x93B0,
    GL_COMPRESSED_RGBA_ASTC_5x4 = 0x93B1,
    GL_COMPRESSED_RGBA_ASTC_5x5 = 0x93B2,
    GL_COMPRESSED_RGBA_ASTC_6x5 = 0x93B3,
    GL_COMPRESSED_RGBA_ASTC_6x6 = 0x93B4,
    GL_COMPRESSED_RGBA_ASTC_8x5 = 0x93B5,
    GL_COMPRESSED_RGBA_ASTC_8x6 = 0x93B6,
    GL_COMPRESSED_RGBA_ASTC_8x8 = 0x93B7,
    GL_COMPRESSED_RGBA_ASTC_10x5 = 0x93B8,
    GL_COMPRESSED_RGBA_ASTC_10x6 = 0x93B9,
    GL_COMPRESSED_RGBA_ASTC_10x8 = 0x93BA,
    GL_COMPRESSED_RGBA_ASTC_10x10 = 0x93BB,
    GL_COMPRESSED_RGBA_ASTC_12x10 = 0x93BC,
    GL_COMPRESSED_RGBA_ASTC_12x12 = 0x93BD,
  }

  export enum DrawMode {
    GL_POINTS = 0x0000,
    GL_LINE_STRIP = 0x0003,
    GL_LINE_LOOP = 0x0002,
    GL_LINES = 0x0001,
    GL_LINE_STRIP_ADJACENCY = 0x000B,
    GL_LINES_ADJACENCY = 0x000A,
    GL_TRIANGLE_STRIP = 0x0005,
    GL_TRIANGLE_FAN = 0x0006,
    GL_TRIANGLES = 0x0004,
    GL_TRIANGLE_STRIP_ADJACENCY = 0x000D,
    GL_TRIANGLES_ADJACENCY = 0x000C,
    GL_PATCHES = 0x000E
  }

  export enum FaceMode {
    GL_FRONT = 0x0404, GL_BACK = 0x0405, GL_FRONT_AND_BACK = 0x0408
  }

  export enum FrameBufferAttachment {
    GL_DEPTH = 0x1801,
    GL_BACK = 0x0405,
    GL_STENCIL = 0x1802,
    GL_DEPTH_ATTACHMENT = 0x8D00,
    GL_COLOR_ATTACHMENT0 = 0x8CE0,
    GL_COLOR_ATTACHMENT1 = 0x8CE1,
    GL_COLOR_ATTACHMENT2 = 0x8CE2,
    GL_COLOR_ATTACHMENT3 = 0x8CE3,
    GL_COLOR_ATTACHMENT4 = 0x8CE4,
    GL_COLOR_ATTACHMENT5 = 0x8CE5,
    GL_COLOR_ATTACHMENT6 = 0x8CE6,
    GL_COLOR_ATTACHMENT7 = 0x8CE7,
    GL_COLOR_ATTACHMENT8 = 0x8CE8,
    GL_COLOR_ATTACHMENT9 = 0x8CE9,
    GL_COLOR_ATTACHMENT10 = 0x8CEA,
    GL_COLOR_ATTACHMENT11 = 0x8CEB,
    GL_COLOR_ATTACHMENT12 = 0x8CEC,
    GL_COLOR_ATTACHMENT13 = 0x8CED,
    GL_COLOR_ATTACHMENT14 = 0x8CEE,
    GL_COLOR_ATTACHMENT15 = 0x8CEF,
    GL_COLOR_ATTACHMENT16 = 0x8CF0,
    GL_COLOR_ATTACHMENT17 = 0x8CF1,
    GL_COLOR_ATTACHMENT18 = 0x8CF2,
    GL_COLOR_ATTACHMENT19 = 0x8CF3,
    GL_COLOR_ATTACHMENT20 = 0x8CF4,
    GL_COLOR_ATTACHMENT21 = 0x8CF5,
    GL_COLOR_ATTACHMENT22 = 0x8CF6,
    GL_COLOR_ATTACHMENT23 = 0x8CF7,
    GL_COLOR_ATTACHMENT24 = 0x8CF8,
    GL_COLOR_ATTACHMENT25 = 0x8CF9,
    GL_COLOR_ATTACHMENT26 = 0x8CFA,
    GL_COLOR_ATTACHMENT27 = 0x8CFB,
    GL_COLOR_ATTACHMENT28 = 0x8CFC,
    GL_COLOR_ATTACHMENT29 = 0x8CFD,
    GL_COLOR_ATTACHMENT30 = 0x8CFE,
    GL_COLOR_ATTACHMENT31 = 0x8CFF,
    GL_DEPTH_STENCIL_ATTACHMENT = 0x821A
  }

  export enum FrameBufferAttachmentParamName {
    GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
    GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
    GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212,
    GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213,
    GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214,
    GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215,
    GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216,
    GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217,
    GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211,
    GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210,
    GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
    GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
    GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7,
    GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4
  }

  export enum FrameBufferStatus {
    GL_FRAMEBUFFER_COMPLETE = 0x8CD5,
    GL_FRAMEBUFFER_UNDEFINED = 0x8219,
    GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
    GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
    GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8
  }

  export enum FrameBufferTarget {
    GL_DRAW_FRAMEBUFFER = 0x8CA9,
    GL_READ_FRAMEBUFFER = 0x8CA8,
    GL_FRAMEBUFFER = 0x8D40
  }

  export enum FrontFaceMode {
    GL_CW = 0x0900,
    GL_CCW = 0x0901,
  }

  export enum Func {
    GL_NEVER = 0x0200,
    GL_LESS = 0x0201,
    GL_EQUAL = 0x0202,
    GL_LEQUAL = 0x0203,
    GL_GREATER = 0x0204,
    GL_NOTEQUAL = 0x0205,
    GL_GEQUAL = 0x0206,
    GL_ALWAYS = 0x0207
  }

  export enum GetStringName {
    GL_EXTENSIONS = 0x1F03,
    GL_RENDERER = 0x1F01,
    GL_SHADING_LANGUAGE_VERSION = 0x8B8C,
    GL_VENDOR = 0x1F00,
    GL_VERSION = 0x1F02,
  }

  export enum GLbitfield {
    GL_COLOR_BUFFER_BIT = 0x00004000,
    GL_DEPTH_BUFFER_BIT = 0x00000100,
    GL_STENCIL_BUFFER_BIT = 0x00000400
  }

  export enum GLCapability {
    GL_BLEND = 0x0BE2,
    GL_CULL_FACE = 0x0B44,
    GL_DEBUG_OUTPUT = 0x92E0,
    GL_DEBUG_OUTPUT_SYNCHRONOUS = 0x8242,
    GL_DEPTH_TEST = 0x0B71,
    GL_DITHER = 0x0BD0,
    GL_POLYGON_OFFSET_FILL = 0x8037,
    GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69,
    GL_RASTERIZER_DISCARD = 0x8C89,
    GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
    GL_SAMPLE_COVERAGE = 0x80A0,
    GL_SAMPLE_MASK = 0x8E51,
    GL_SCISSOR_TEST = 0x0C11,
    GL_STENCIL_TEST = 0x0B90
  }

  export enum GLError {
    GL_NO_ERROR = 0,
    GL_INVALID_ENUM = 0x0500,
    GL_INVALID_VALUE = 0x0501,
    GL_INVALID_OPERATION = 0x0502,
    GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506,
    GL_OUT_OF_MEMORY = 0x0505,
    GL_STACK_UNDERFLOW = 0x0504,
    GL_STACK_OVERFLOW = 0x0503,
  }

  export enum HintMode {
    GL_FASTEST = 0x1101,
    GL_NICEST = 0x1102,
    GL_DONT_CARE = 0x1100,
  }

  export enum HintTarget {
    GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
    GL_GENERATE_MIPMAP_HINT = 0x8192
  }

  export enum IndicesType {
    GL_UNSIGNED_BYTE = 0x1401,
    GL_UNSIGNED_SHORT = 0x1403,
    GL_UNSIGNED_INT = 0x1405,
    GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368,
    GL_INT = 0x1404,
    GL_FLOAT = 0x1406,
    GL_BYTE = 0x1400,
    GL_SHORT = 0x1402,
    GL_HALF_FLOAT = 0x140B,
    GL_UNSIGNED_SHORT_5_6_5 = 0x8363,
    GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033,
    GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034,
    GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B,
    GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E,
    GL_UNSIGNED_INT_24_8 = 0x84FA,
    GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD,
  }

  export enum InternalFormat {
    GL_R8 = 0x8229,
    GL_RED = 0x1903,
    GL_R8UI = 0x8232,
    GL_RED_INTEGER = 0x8D94,
    GL_R8I = 0x8231,
    GL_R16UI = 0x8234,
    GL_R16I = 0x8233,
    GL_R32UI = 0x8236,
    GL_R32I = 0x8235,
    GL_RG8 = 0x822B,
    GL_RG = 0x8227,
    GL_RG8UI = 0x8238,
    GL_RG_INTEGER = 0x8228,
    GL_RG8I = 0x8237,
    GL_RG16UI = 0x823A,
    GL_RG16I = 0x8239,
    GL_RG32UI = 0x823C,
    GL_RG32I = 0x823B,
    GL_RGB8 = 0x8051,
    GL_RGB = 0x1907,
    GL_RGB565 = 0x8D62,
    GL_RGBA8 = 0x8058,
    GL_RGBA = 0x1908,
    GL_SRGB8_ALPHA8 = 0x8C43,
    GL_RGB5_A1 = 0x8057,
    GL_RGBA4 = 0x8056,
    GL_RGB10_A2 = 0x8059,
    GL_RGBA8UI = 0x8D7C,
    GL_RGBA_INTEGER = 0x8D99,
    GL_RGBA8I = 0x8D8E,
    GL_RGB10_A2UI = 0x906F,
    GL_RGBA16UI = 0x8D76,
    GL_RGBA16I = 0x8D88,
    GL_RGBA32I = 0x8D82,
    GL_RGBA32UI = 0x8D70,
    GL_DEPTH_COMPONENT16 = 0x81A5,
    GL_DEPTH_COMPONENT = 0x1902,
    GL_DEPTH_COMPONENT24 = 0x81A6,
    GL_DEPTH_COMPONENT32F = 0x8CAC,
    GL_DEPTH24_STENCIL8 = 0x88F0,
    GL_DEPTH_STENCIL = 0x84F9,
    GL_DEPTH32F_STENCIL8 = 0x8CAD,
    GL_STENCIL_INDEX8 = 0x8D48,
    GL_STENCIL = 0x1802,
  }

  export enum MipmapTarget {
    GL_TEXTURE_2D = 0x0DE1,
    GL_TEXTURE_3D = 0x806F,
    GL_TEXTURE_2D_ARRAY = 0x8C1A,
    GL_TEXTURE_CUBE_MAP = 0x8513,
    GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009,
  }

  export enum ParamName {
    GL_ACTIVE_TEXTURE = 0x84E0,
    GL_ALIASED_LINE_WIDTH_RANGE = 0x846E,
    GL_ALIASED_POINT_SIZE_RANGE = 0x846D,
    GL_ALPHA_BITS = 0x0D55,
    GL_ARRAY_BUFFER_BINDING = 0x8894,
    GL_BLEND = 0x0BE2,
    GL_BLEND_COLOR = 0x8005,
    GL_BLEND_DST_ALPHA = 0x80CA,
    GL_BLEND_DST_RGB = 0x80C8,
    GL_BLEND_EQUATION_ALPHA = 0x883D,
    GL_BLEND_EQUATION_RGB = 0x8009,
    GL_BLEND_SRC_ALPHA = 0x80CB,
    GL_BLEND_SRC_RGB = 0x80C9,
    GL_BLUE_BITS = 0x0D54,
    GL_COLOR_CLEAR_VALUE = 0x0C22,
    GL_COLOR_WRITEMASK = 0x0C23,
    GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3,
    GL_CONTEXT_FLAGS = 0x821E,
    // GL_CONTEXT_ROBUST_ACCESS = undefined,
    GL_COPY_READ_BUFFER_BINDING = 0x8F36,
    GL_COPY_WRITE_BUFFER_BINDING = 0x8F37,
    GL_CULL_FACE = 0x0B44,
    GL_CULL_FACE_MODE = 0x0B45,
    GL_CURRENT_PROGRAM = 0x8B8D,
    GL_DEBUG_GROUP_STACK_DEPTH = 0x826D,
    GL_DEBUG_LOGGED_MESSAGES = 0x9145,
    GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243,
    GL_DEPTH_BITS = 0x0D56,
    GL_DEPTH_CLEAR_VALUE = 0x0B73,
    GL_DEPTH_FUNC = 0x0B74,
    GL_DEPTH_RANGE = 0x0B70,
    GL_DEPTH_TEST = 0x0B71,
    GL_DEPTH_WRITEMASK = 0x0B72,
    GL_DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF,
    GL_DITHER = 0x0BD0,
    // GL_DRAW_BUFFER = undefined,
    GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6,
    GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895,
    GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D,
    GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
    GL_FRONT_FACE = 0x0B46,
    GL_GENERATE_MIPMAP_HINT = 0x8192,
    GL_GREEN_BITS = 0x0D53,
    GL_IMAGE_BINDING_LAYERED = 0x8F3C,
    GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
    GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
    GL_LAYER_PROVOKING_VERTEX = 0x825E,
    GL_LINE_WIDTH = 0x0B21,
    GL_MAJOR_VERSION = 0x821B,
    GL_MAX_3D_TEXTURE_SIZE = 0x8073,
    GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF,
    GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC,
    GL_MAX_COLOR_ATTACHMENTS = 0x8CDF,
    GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E,
    GL_MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7,
    GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1,
    GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266,
    GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33,
    GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32,
    GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC,
    GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E,
    GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F,
    GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
    GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E,
    GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31,
    GL_MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265,
    GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264,
    GL_MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD,
    GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB,
    GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC,
    GL_MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB,
    GL_MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263,
    GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB,
    GL_MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE,
    GL_MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF,
    GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C,
    GL_MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C,
    GL_MAX_DEBUG_LOGGED_MESSAGES = 0x9144,
    GL_MAX_DEBUG_MESSAGE_LENGTH = 0x9143,
    GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F,
    GL_MAX_DRAW_BUFFERS = 0x8824,
    GL_MAX_ELEMENT_INDEX = 0x8D6B,
    GL_MAX_ELEMENTS_INDICES = 0x80E9,
    GL_MAX_ELEMENTS_VERTICES = 0x80E8,
    GL_MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6,
    GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0,
    GL_MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE,
    GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125,
    GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C,
    GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA,
    GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D,
    GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49,
    GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD,
    GL_MAX_FRAMEBUFFER_HEIGHT = 0x9316,
    GL_MAX_FRAMEBUFFER_LAYERS = 0x9317,
    GL_MAX_FRAMEBUFFER_SAMPLES = 0x9318,
    GL_MAX_FRAMEBUFFER_WIDTH = 0x9315,
    GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF,
    GL_MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5,
    GL_MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD,
    GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123,
    GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124,
    GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0,
    GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7,
    GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A,
    GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29,
    GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1,
    GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C,
    GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF,
    GL_MAX_INTEGER_SAMPLES = 0x9110,
    GL_MAX_LABEL_LENGTH = 0x82E8,
    GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905,
    GL_MAX_RENDERBUFFER_SIZE = 0x84E8,
    GL_MAX_SAMPLE_MASK_WORDS = 0x8E59,
    GL_MAX_SAMPLES = 0x8D57,
    GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111,
    GL_MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE,
    GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD,
    GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD,
    GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3,
    GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB,
    GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C,
    GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83,
    GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8,
    GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81,
    GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85,
    GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89,
    GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F,
    GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE,
    GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4,
    GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC,
    GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D,
    GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86,
    GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9,
    GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82,
    GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A,
    GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80,
    GL_MAX_TESS_GEN_LEVEL = 0x8E7E,
    GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84,
    GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B,
    GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872,
    GL_MAX_TEXTURE_LOD_BIAS = 0x84FD,
    GL_MAX_TEXTURE_SIZE = 0x0D33,
    GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
    GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
    GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
    GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30,
    GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F,
    GL_MAX_UNIFORM_LOCATIONS = 0x826E,
    GL_MAX_VARYING_COMPONENTS = 0x8B4B,
    GL_MAX_VARYING_VECTORS = 0x8DFC,
    GL_MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2,
    GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC,
    GL_MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA,
    GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9,
    GL_MAX_VERTEX_ATTRIBS = 0x8869,
    GL_MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA,
    GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6,
    GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
    GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122,
    GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B,
    GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A,
    GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB,
    GL_MAX_VIEWPORT_DIMS = 0x0D3A,
    GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B,
    GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904,
    GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37,
    GL_MINOR_VERSION = 0x821C,
    GL_MULTISAMPLE_LINE_WIDTH_RANGE = 0x9381,
    GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
    GL_NUM_EXTENSIONS = 0x821D,
    GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE,
    GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9,
    GL_PACK_ALIGNMENT = 0x0D05,
    GL_PACK_ROW_LENGTH = 0x0D02,
    GL_PACK_SKIP_PIXELS = 0x0D04,
    GL_PACK_SKIP_ROWS = 0x0D03,
    GL_PATCH_VERTICES = 0x8E72,
    GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED,
    GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF,
    GL_POLYGON_OFFSET_FACTOR = 0x8038,
    GL_POLYGON_OFFSET_FILL = 0x8037,
    GL_POLYGON_OFFSET_UNITS = 0x2A00,
    GL_PRIMITIVE_BOUNDING_BOX = 0x92BE,
    GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69,
    GL_PROGRAM_BINARY_FORMATS = 0x87FF,
    GL_PROGRAM_PIPELINE_BINDING = 0x825A,
    GL_RASTERIZER_DISCARD = 0x8C89,
    GL_READ_BUFFER = 0x0C02,
    GL_READ_FRAMEBUFFER_BINDING = 0x8CAA,
    GL_RED_BITS = 0x0D52,
    GL_RENDERBUFFER_BINDING = 0x8CA7,
    GL_RESET_NOTIFICATION_STRATEGY = 0x8256,
    GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
    GL_SAMPLE_BUFFERS = 0x80A8,
    GL_SAMPLE_COVERAGE = 0x80A0,
    GL_SAMPLE_COVERAGE_INVERT = 0x80AB,
    GL_SAMPLE_COVERAGE_VALUE = 0x80AA,
    GL_SAMPLE_MASK_VALUE = 0x8E52,
    GL_SAMPLE_SHADING = 0x8C36,
    GL_SAMPLER_BINDING = 0x8919,
    GL_SAMPLES = 0x80A9,
    GL_SCISSOR_BOX = 0x0C10,
    GL_SCISSOR_TEST = 0x0C11,
    GL_SHADER_BINARY_FORMATS = 0x8DF8,
    GL_SHADER_COMPILER = 0x8DFA,
    GL_SHADER_STORAGE_BUFFER_BINDING = 0x90D3,
    GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF,
    GL_SHADER_STORAGE_BUFFER_SIZE = 0x90D5,
    GL_SHADER_STORAGE_BUFFER_START = 0x90D4,
    GL_STENCIL_BACK_FAIL = 0x8801,
    GL_STENCIL_BACK_FUNC = 0x8800,
    GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802,
    GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803,
    GL_STENCIL_BACK_REF = 0x8CA3,
    GL_STENCIL_BACK_VALUE_MASK = 0x8CA4,
    GL_STENCIL_BACK_WRITEMASK = 0x8CA5,
    GL_STENCIL_BITS = 0x0D57,
    GL_STENCIL_CLEAR_VALUE = 0x0B91,
    GL_STENCIL_FAIL = 0x0B94,
    GL_STENCIL_FUNC = 0x0B92,
    GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95,
    GL_STENCIL_PASS_DEPTH_PASS = 0x0B96,
    GL_STENCIL_REF = 0x0B97,
    GL_STENCIL_TEST = 0x0B90,
    GL_STENCIL_VALUE_MASK = 0x0B93,
    GL_STENCIL_WRITEMASK = 0x0B98,
    GL_SUBPIXEL_BITS = 0x0D50,
    GL_TEXTURE_BINDING_2D = 0x8069,
    GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D,
    GL_TEXTURE_BINDING_3D = 0x806A,
    GL_TEXTURE_BINDING_BUFFER = 0x8C2C,
    GL_TEXTURE_BINDING_CUBE_MAP = 0x8514,
    GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104,
    GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105,
    GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A,
    GL_TEXTURE_BUFFER_BINDING = 0x8C2A,
    GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F,
    GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25,
    GL_TRANSFORM_FEEDBACK_ACTIVE = 0x8E24,
    GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
    GL_TRANSFORM_FEEDBACK_PAUSED = 0x8E23,
    GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
    GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
    GL_UNIFORM_BUFFER_BINDING = 0x8A28,
    GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34,
    GL_UNIFORM_BUFFER_SIZE = 0x8A2A,
    GL_UNIFORM_BUFFER_START = 0x8A29,
    GL_UNPACK_ALIGNMENT = 0x0CF5,
    GL_UNPACK_IMAGE_HEIGHT = 0x806E,
    GL_UNPACK_ROW_LENGTH = 0x0CF2,
    GL_UNPACK_SKIP_IMAGES = 0x806D,
    GL_UNPACK_SKIP_PIXELS = 0x0CF4,
    GL_UNPACK_SKIP_ROWS = 0x0CF3,
    GL_VERTEX_ARRAY_BINDING = 0x85B5,
    GL_VERTEX_BINDING_DIVISOR = 0x82D6,
    GL_VERTEX_BINDING_OFFSET = 0x82D7,
    GL_VERTEX_BINDING_STRIDE = 0x82D8,
    GL_VIEWPORT = 0x0BA2,
  }

  export enum PixelFormat {
    GL_RGBA = 0x1908,
    GL_RGBA_INTEGER = 0x8D99,
  }

  export enum PixelStorageMode {
    GL_PACK_ROW_LENGTH = 0x0D02,
    GL_PACK_SKIP_PIXELS = 0x0D04,
    GL_PACK_SKIP_ROWS = 0x0D03,
    GL_PACK_ALIGNMENT = 0x0D05,
    GL_UNPACK_ROW_LENGTH = 0x0CF2,
    GL_UNPACK_IMAGE_HEIGHT = 0x806E,
    GL_UNPACK_SKIP_PIXELS = 0x0CF4,
    GL_UNPACK_SKIP_ROWS = 0x0CF3,
    GL_UNPACK_SKIP_IMAGES = 0x806D,
    GL_UNPACK_ALIGNMENT = 0x0CF5,
  }

  export enum PrecisionType {
    GL_LOW_FLOAT = 0x8DF0,
    GL_MEDIUM_FLOAT = 0x8DF1,
    GL_HIGH_FLOAT = 0x8DF2,
    GL_LOW_INT = 0x8DF3,
    GL_MEDIUM_INT = 0x8DF4,
    GL_HIGH_INT = 0x8DF5,
  }

  export enum RenderBufferTarget {
    GL_RENDERBUFFER = 0x8D41
  }

  export enum RenderBufferParamName {
    GL_RENDERBUFFER_WIDTH = 0x8D42,
    GL_RENDERBUFFER_HEIGHT = 0x8D43,
    GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
    GL_RENDERBUFFER_RED_SIZE = 0x8D50,
    GL_RENDERBUFFER_GREEN_SIZE = 0x8D51,
    GL_RENDERBUFFER_BLUE_SIZE = 0x8D52,
    GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53,
    GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54,
    GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55,
    GL_RENDERBUFFER_SAMPLES = 0x8CAB
  }

  export enum ShaderParamName {
    GL_SHADER_TYPE = 0x8B4F,
    GL_DELETE_STATUS = 0x8B80,
    GL_COMPILE_STATUS = 0x8B81,
    GL_INFO_LOG_LENGTH = 0x8B84,
    GL_SHADER_SOURCE_LENGTH = 0x8B88
  }

  export enum ShaderType {
    GL_COMPUTE_SHADER = 0x91B9,
    GL_VERTEX_SHADER = 0x8B31,
    GL_TESS_CONTROL_SHADER = 0x8E88,
    GL_TESS_EVALUATION_SHADER = 0x8E87,
    GL_GEOMETRY_SHADER = 0x8DD9,
    GL_FRAGMENT_SHADER = 0x8B30,
  }

  export enum TestFail {
    GL_KEEP = 0x1E00,
    GL_ZERO = 0,
    GL_REPLACE = 0x1E01,
    GL_INCR = 0x1E02,
    GL_INCR_WRAP = 0x8507,
    GL_DECR = 0x1E03,
    GL_DECR_WRAP = 0x8508,
    GL_INVERT = 0x150A,
  }

  export enum TexImage2DTarget {
    GL_TEXTURE_2D = 0x0DE1,
    GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
    GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
    GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
    GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
    GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
    GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A
  }

  export enum TexParamName {
    GL_DEPTH_STENCIL_TEXTURE_MODE = 0x90EA,
    GL_IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7,
    GL_TEXTURE_BASE_LEVEL = 0x813C,
    GL_TEXTURE_COMPARE_FUNC = 0x884D,
    GL_TEXTURE_COMPARE_MODE = 0x884C,
    GL_TEXTURE_IMMUTABLE_FORMAT = 0x912F,
    GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF,
    GL_TEXTURE_MAG_FILTER = 0x2800,
    GL_TEXTURE_MAX_LEVEL = 0x813D,
    GL_TEXTURE_MAX_LOD = 0x813B,
    GL_TEXTURE_MIN_FILTER = 0x2801,
    GL_TEXTURE_MIN_LOD = 0x813A,
    GL_TEXTURE_SWIZZLE_R = 0x8E42,
    GL_TEXTURE_SWIZZLE_G = 0x8E43,
    GL_TEXTURE_SWIZZLE_B = 0x8E44,
    GL_TEXTURE_SWIZZLE_A = 0x8E45,
    GL_TEXTURE_WRAP_S = 0x2802,
    GL_TEXTURE_WRAP_T = 0x2803,
    GL_TEXTURE_WRAP_R = 0x8072,
    GL_TEXTURE_BORDER_COLOR = 0x1004,
  }

  export enum TextureTarget {
    GL_TEXTURE_2D = 0x0DE1,
    GL_TEXTURE_3D = 0x806F,
    GL_TEXTURE_2D_ARRAY = 0x8C1A,
    GL_TEXTURE_CUBE_MAP = 0x8513,
    GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009,
    GL_TEXTURE_BUFFER = 0x8C2A,
    GL_TEXTURE_2D_MULTISAMPLE = 0x9100,
    GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
    GL_TEXTURE_EXTERNAL_OES = 0x8D65
  }

  export enum VertexAttribParamName {
    GL_CURRENT_VERTEX_ATTRIB = 0x8626,
    GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
    GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622,
    GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
    GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
    GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
    GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
    GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
    GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE,
    GL_VERTEX_ATTRIB_BINDING = 0x82D4,
  }

  export enum ProgramParamName {
    GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9,
    GL_ACTIVE_ATTRIBUTES = 0x8B89,
    GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A,
    GL_ACTIVE_UNIFORMS = 0x8B86,
    GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36,
    GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35,
    GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87,
    GL_ATTACHED_SHADERS = 0x8B85,
    GL_COMPUTE_WORK_GROUP_SIZE = 0x8267,
    GL_DELETE_STATUS = 0x8B80,
    // GL_GEOMETRY_LINKED_INPUT_TYPE = undefined,
    // GL_GEOMETRY_LINKED_OUTPUT_TYPE = undefined,
    // GL_GEOMETRY_LINKED_VERTICES_OUT = undefined,
    GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F,
    GL_INFO_LOG_LENGTH = 0x8B84,
    GL_LINK_STATUS = 0x8B82,
    GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257,
    GL_PROGRAM_SEPARABLE = 0x8258,
    GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75,
    GL_TESS_GEN_MODE = 0x8E76,
    GL_TESS_GEN_POINT_MODE = 0x8E79,
    GL_TESS_GEN_SPACING = 0x8E77,
    GL_TESS_GEN_VERTEX_ORDER = 0x8E78,
    GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F,
    GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83,
    GL_TRANSFORM_FEEDBACK_VARYING_MA
  }

  export enum BufferAccessMode {
    GL_READ_ONLY = 0x88B8,
    GL_WRITE_ONLY = 0x88B9,
    GL_READ_WRITE = 0x88BA,
  }

  export function glActiveShaderProgram(pipeline: number, program: number): void;

  export function glActiveTexture(texture: GLTexture): void;

  export function glAttachShader(program: number, shader: number): void;

  export function glBeginQuery(target: QueryTarget, id: number): void;

  export function glEndQuery(target: QueryTarget): void;

  export function glBeginTransformFeedback(primitiveMode: PrimitiveMode): void;

  export function glEndTransformFeedback(): void;

  export function glBindAttribLocation(program: number, index: number, name: number): void;

  export function glBindBuffer(target: BufferType, buffer: number): void;

  export function glBindFramebuffer(target: FrameBufferTarget, framebuffer: number): void;

  /*** * @param target must be GL_RENDERBUFFER. */
  export function glBindRenderbuffer(target: RenderBufferTarget, renderbuffer: number): void;

  export function glBindTexture(target: TextureTarget, texture: number): void;

  export function glBlendColor(red: number, green: number, blue: number, alpha: number): void;

  export function glBlendEquation(mode: BlendMode): void;

  export function glBlendEquationi(buffer: number, mode: BlendMode): void;

  export function glBlendEquationSeparate(modeRGB: BlendMode, modeAlpha: BlendMode): void;

  export function glBlendFunc(sfactor: BlendingFactors, dfactor: BlendingFactors): void;

  export function glBlendFuncSeparate(sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
    sfactorAlpha: BlendingFactors, dfactorAlpha: BlendingFactors): void;

  export function glBlendFuncSeparatei(buffer: number, sfactorRGB: BlendingFactors, dfactorRGB: BlendingFactors,
    sfactorAlpha: BlendingFactors, dfactorAlpha: BlendingFactors): void;

  export function glBufferData(target: BufferType, data: ArrayBufferLike, usage: BufferUsage): void;

  export function glBufferSubData(target: BufferType, offset: number, data: ArrayBufferLike): void;

  export function glCheckFramebufferStatus(target: FrameBufferTarget): FrameBufferStatus;

  export function glClear(mask: GLbitfield): void;

  export function glClearColor(red: number, green: number, blue: number, aplha: number): void;

  export function glClearDepthf(d: number): void;

  export function glClearStencil(s: number): void;

  export function glColorMask(red: GLboolean, green: GLboolean, blue: GLboolean, alpha: GLboolean): void;

  export function glCompileShader(shader: number): void;

  export function glCompressedTexImage2D(target: TexImage2DTarget, level: number,
    internalformat: CompressedInternalFormat, width: number, height: number, border: number,
    data: ArrayBufferLike): void;

  export function glCompressedTexSubImage2D(target: TexImage2DTarget, level: number, xoffset: number, yoffset: number,
    width: number, height: number, format: CompressedInternalFormat, data: ArrayBufferLike): void;

  export function glCopyTexImage2D(target: TexImage2DTarget, level: number, internalformat: InternalFormat, x: number,
    y: number, width: number, height: number, border: number): void;

  export function glCopyTexSubImage2D(target: TexImage2DTarget, level: number, xoffset: number, yoffset: number,
    x: number, y: number, width: number, height: number): void;

  export function glCreateProgram(): number;

  export function glCreateShader(type: ShaderType): number;

  export function glCullFace(mode: FaceMode): void;

  export function glDeleteBuffers(buffers: number[]): void;

  export function glDeleteVertexArrays(arrays: number[]): void;

  export function glDeleteFramebuffers(buffers: number[]): void;

  export function glDeleteProgram(program: number): void;

  export function glDeleteRenderbuffers(buffers: number[]): void;

  export function glDeleteShader(program: number): void;

  export function glDeleteTextures(textures: number[]): void;

  export function glDepthFunc(func: Func): void;

  export function glDepthMask(flag: GLboolean): void;

  export function glDepthRangef(n: number, f: number): void;

  export function glDetachShader(program: number, shader: number): void;

  export function glDisable(cap: GLCapability): void;

  export function glDisableVertexAttribArray(index: number): void;

  export function glDrawArrays(mode: DrawMode, first: number, count: number): void;

  export function glDrawElements(mode: DrawMode, count: number, type: IndicesType, indices: ArrayBufferLike): void;

  export function glEnable(cap: GLCapability): void;

  export function glEnableVertexAttribArray(index: number): void;

  export function glFinish(): void;

  export function glFlush(): void;

  export function glFramebufferRenderbuffer(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    renderbuffertarget: RenderBufferTarget, renderbuffer: number): void;

  export function glFramebufferTexture2D(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    textarget: TextureTarget, texture: number, level: number): void;

  export function glFrontFace(mode: FrontFaceMode): void;

  export function glGenBuffers(n: number): Uint32Array;

  export function glGenVertexArrays(n: number): Uint32Array;

  /*** * @param target not accept GL_TEXTURE_BUFFE,GL_TEXTURE_2D_MULTISAMPLE,GL_TEXTURE_2D_MULTISAMPLE_ARRAY */
  export function glGenerateMipmap(target: MipmapTarget): void;

  export function glGenFramebuffers(n: number): Uint32Array;

  export function glGenRenderbuffers(n: number): Uint32Array;

  export function glGenTextures(n: number): Uint32Array;

  export function glGetActiveAttrib(program: number, index: number): GLActiveAttrib;

  export function glGetActiveUniform(program: number, index: number): GLActiveAttrib;

  export function glGetAttachedShaders(program: number): Uint32Array;

  export function glGetAttribLocation(program: number, name: string): number;

  export function glGetBufferParameteriv(target: BufferType, pname: BufferParamName): number;

  export function glGetBufferParameteri64v(target: BufferType, value: BufferParamName): number;

  export function glGetError(): GLError;

  /*** * @param pname enum ParamName * @param size buffer size */
  export function glGetFloatv(pname: ParamName, size: number): Float32Array;

  /*** * @param pname enum ParamName * @param size buffer size */
  export function glGetBooleanv(pname: ParamName, size: number): ArrayBuffer;

  /*** * @param pname enum ParamName * @param size buffer size */
  export function glGetIntegerv(pname: ParamName, size: number): Int32Array;

  /*** * @param pname enum ParamName * @param size buffer size */
  export function glGetInteger64v(pname: ParamName, size: number): BigInt64Array;

  export function glGetFramebufferAttachmentParameteriv(target: FrameBufferTarget, attachment: FrameBufferAttachment,
    pname: FrameBufferAttachmentParamName): number;

  export function glGetProgramiv(program: number, pname: ProgramParamName): number;

  export function glGetProgramInfoLog(program: number): string;

  export function glGetRenderbufferParameteriv(target: RenderBufferTarget, pname: RenderBufferParamName): number;

  export function glGetShaderiv(shader: number, pname: ShaderParamName): number;

  export function glGetShaderInfoLog(shader: number): string;

  /*** * shaderType must be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER. */
  export function glGetShaderPrecisionFormat(shadertype: ShaderType, precisiontype: PrecisionType): GLPrecision;

  export function glGetShaderSource(shader: number): string;

  export function glGetString(name: GetStringName): string;

  export function glGetTexParameterfv(target: TextureTarget, pname: TexParamName): number;

  export function glGetTexParameteriv(target: TextureTarget, pname: TexParamName): number;

  export function glGetUniformfv(program: number, location: number): number;

  export function glGetUniformiv(program: number, location: number): number;

  export function glGetUniformLocation(program: number, name: string): number;

  export function glGetVertexAttribfv(index: number, pname: VertexAttribParamName): Float32Array;

  export function glGetVertexAttribiv(index: number, pname: VertexAttribParamName): Int32Array;

  /*** * @deprecated 方法未实现 */
  export function glGetVertexAttribPointerv(): void;

  export function glHint(target: HintTarget, mode: HintMode): void;

  export function glIsBuffer(buffer: number): GLboolean;

  export function glIsEnabled(cap: GLCapability): GLboolean;

  export function glIsFramebuffer(framebuffer: number): GLboolean;

  export function glIsRenderbuffer(renderbuffer: number): GLboolean;

  export function glIsShader(shader: number): GLboolean;

  export function glIsTexture(texture: number): GLboolean;

  export function glLineWidth(width: number): void;

  export function glLinkProgram(program: number): void;

  export function glPixelStorei(pname: PixelStorageMode, param: number): void;

  export function glPolygonOffset(factor: number, units: number): void;

  export function glReadPixels(x: number, y: number, width: number, height: number, format: PixelFormat,
    type: IndicesType): ArrayBuffer;

  export function glReleaseShaderCompiler(): void;

  export function glRenderbufferStorage(target: RenderBufferTarget, internalformat: InternalFormat, width: number,
    height: number): void;

  export function glSampleCoverage(value: number, invert: GLboolean): void;

  export function glScissor(x: number, y: number, width: number, height: number): void;

  /*** * @deprecated 方法未实现 */
  export function glShaderBinary(): void;

  export function glShaderSource(shader: number, source: string): void;

  export function glStencilFunc(func: Func, ref: number, mask: number): void;

  export function glStencilFuncSeparate(face: FaceMode, func: Func, ref: number, mask: number): void;

  export function glStencilMask(mask: number): void;

  export function glStencilMaskSeparate(face: FaceMode, mask: number): void;

  export function glStencilOp(fail: TestFail, zfail: TestFail, zpass: TestFail): void;

  export function glStencilOpSeparate(face: FaceMode, sfail: TestFail, dpfail: TestFail, dppass: TestFail): void;

  export function glTexImage2D(target: TextureTarget, level: number, internalformat: number, width: number,
    height: number, border: number, format: InternalFormat, type: IndicesType, pixels: ArrayBufferLike): void;

  export function glTexParameterf(target: TextureTarget, pname: TexParamName, param: number): void;

  export function glTexParameterfv(target: TextureTarget, pname: TexParamName, params: number[]): void;

  export function glTexParameteri(target: TextureTarget, pname: TexParamName, param: number): void;

  export function glTexParameteriv(target: TextureTarget, pname: TexParamName, params: number[]): void;

  export function glTexSubImage2D(target: TextureTarget, level: number, xoffset: number, yoffset: number, width: number,
    height: number, format: InternalFormat, type: IndicesType, pixels: ArrayBufferLike): void;

  export function glUniform1f(location: number, v0: number): void;

  export function glUniform1fv(location: number, values: number[]): void;

  export function glUniform1i(location: number, v0: number): void;

  export function glUniform1iv(location: number, values: number[]): void;

  export function glUniform2f(location: number, v0: number, v1: number): void;

  export function glUniform2fv(location: number, values: number[]): void;

  export function glUniform2i(location: number, v0: number, v1: number): void;

  export function glUniform2iv(location: number, values: number[]): void;

  export function glUniform3f(location: number, v0: number, v1: number, v2: number): void;

  export function glUniform3fv(location: number, values: number[]): void;

  export function glUniform3i(location: number, v0: number, v1: number, v2: number): void;

  export function glUniform3iv(location: number, values: number[]): void;

  export function glUniform4f(location: number, v0: number, v1: number, v2: number, v3: number): void;

  export function glUniform4fv(location: number, values: number[]): void;

  export function glUniform4i(location: number, v0: number, v1: number, v2: number, v3: number): void;

  export function glUniform4iv(location: number, values: number[]): void;

  export function glViewport(x: number, y: number, width: number, height: number): void;

  export function glVertexAttribPointer(index: number, size: number, type: IndicesType, normalized: GLboolean,
    stride: number, pointer: number): void;

  export function glUniformMatrix2fv(location: number, count: number, transpose: GLboolean, value: number[]): void;

  export function glUniformMatrix3fv(location: number, count: number, transpose: GLboolean, value: number[]): void;

  export function glUniformMatrix4fv(location: number, count: number, transpose: GLboolean, value: number[]): void;

  export function glUseProgram(program: number): void;

  export function glValidateProgram(program: number): void;

  export function glVertexAttrib1f(index: number, x: number): void;

  export function glVertexAttrib2f(index: number, x: number, y: number): void;

  export function glVertexAttrib3f(index: number, x: number, y: number, z: number): void;

  export function glVertexAttrib4f(index: number, x: number, y: number, z: number, w: number): void;

  export function glVertexAttrib1fv(index: number, v: number[]): void;

  export function glVertexAttrib2fv(index: number, v: number[]): void;

  export function glVertexAttrib3fv(index: number, v: number[]): void;

  export function glVertexAttrib4fv(index: number, v: number[]): void;

  export function glBindVertexArray(array: number): void;

  export function glBindVertexBuffer(bindingindex: number, buffer: number, offset: number, stride: number): void;

  /**
   * @since 0.2.0
   * @param attribindex
   * @param size
   * @param type
   * @param normalized
   * @param relativeoffset
   */
  export function glVertexAttribFormat(attribindex: number, size: number, type: IndicesType, normalized: GLboolean,
    relativeoffset: number): void;

  /**
   * @since 0.2.0
   * @param attribindex
   * @param size
   * @param type
   * @param relativeoffset
   */
  export function glVertexAttribIFormat(attribindex: number, size: number, type: IndicesType, relativeoffset: number)

  /**
   * @since 0.2.0
   * @param attribindex
   * @param bindingindex
   */
  export function glVertexAttribBinding(attribindex: number, bindingindex: number): void;

  export const GL_DEPTH_BUFFER_BIT = 0x00000100;

  export const GL_STENCIL_BUFFER_BIT = 0x00000400;

  export const GL_COLOR_BUFFER_BIT = 0x00004000;

  export const GL_FALSE = 0;

  export const GL_TRUE = 1;

  export const GL_POINTS = 0x0000;

  export const GL_LINES = 0x0001;

  export const GL_LINE_LOOP = 0x0002;

  export const GL_LINE_STRIP = 0x0003;

  export const GL_TRIANGLES = 0x0004;

  export const GL_TRIANGLE_STRIP = 0x0005;

  export const GL_TRIANGLE_FAN = 0x0006;

  export const GL_ZERO = 0;

  export const GL_ONE = 1;

  export const GL_SRC_COLOR = 0x0300;

  export const GL_ONE_MINUS_SRC_COLOR = 0x0301;

  export const GL_SRC_ALPHA = 0x0302;

  export const GL_ONE_MINUS_SRC_ALPHA = 0x0303;

  export const GL_DST_ALPHA = 0x0304;

  export const GL_ONE_MINUS_DST_ALPHA = 0x0305;

  export const GL_DST_COLOR = 0x0306;

  export const GL_ONE_MINUS_DST_COLOR = 0x0307;

  export const GL_SRC_ALPHA_SATURATE = 0x0308;

  export const GL_FUNC_ADD = 0x8006;

  export const GL_BLEND_EQUATION = 0x8009;

  export const GL_BLEND_EQUATION_RGB = 0x8009;

  export const GL_BLEND_EQUATION_ALPHA = 0x883D;

  export const GL_FUNC_SUBTRACT = 0x800A;

  export const GL_FUNC_REVERSE_SUBTRACT = 0x800B;

  export const GL_BLEND_DST_RGB = 0x80C8;

  export const GL_BLEND_SRC_RGB = 0x80C9;

  export const GL_BLEND_DST_ALPHA = 0x80CA;

  export const GL_BLEND_SRC_ALPHA = 0x80CB;

  export const GL_CONSTANT_COLOR = 0x8001;

  export const GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;

  export const GL_CONSTANT_ALPHA = 0x8003;

  export const GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;

  export const GL_BLEND_COLOR = 0x8005;

  export const GL_ARRAY_BUFFER = 0x8892;

  export const GL_ELEMENT_ARRAY_BUFFER = 0x8893;

  export const GL_ARRAY_BUFFER_BINDING = 0x8894;

  export const GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;

  export const GL_STREAM_DRAW = 0x88E0;

  export const GL_STATIC_DRAW = 0x88E4;

  export const GL_DYNAMIC_DRAW = 0x88E8;

  export const GL_BUFFER_SIZE = 0x8764;

  export const GL_BUFFER_USAGE = 0x8765;

  export const GL_CURRENT_VERTEX_ATTRIB = 0x8626;

  export const GL_FRONT = 0x0404;

  export const GL_BACK = 0x0405;

  export const GL_FRONT_AND_BACK = 0x0408;

  export const GL_TEXTURE_2D = 0x0DE1;

  export const GL_CULL_FACE = 0x0B44;

  export const GL_BLEND = 0x0BE2;

  export const GL_DITHER = 0x0BD0;

  export const GL_STENCIL_TEST = 0x0B90;

  export const GL_DEPTH_TEST = 0x0B71;

  export const GL_SCISSOR_TEST = 0x0C11;

  export const GL_POLYGON_OFFSET_FILL = 0x8037;

  export const GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;

  export const GL_SAMPLE_COVERAGE = 0x80A0;

  export const GL_NO_ERROR = 0;

  export const GL_INVALID_ENUM = 0x0500;

  export const GL_INVALID_VALUE = 0x0501;

  export const GL_INVALID_OPERATION = 0x0502;

  export const GL_OUT_OF_MEMORY = 0x0505;

  export const GL_CW = 0x0900;

  export const GL_CCW = 0x0901;

  export const GL_LINE_WIDTH = 0x0B21;

  export const GL_ALIASED_POINT_SIZE_RANGE = 0x846D;

  export const GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;

  export const GL_CULL_FACE_MODE = 0x0B45;

  export const GL_FRONT_FACE = 0x0B46;

  export const GL_DEPTH_RANGE = 0x0B70;

  export const GL_DEPTH_WRITEMASK = 0x0B72;

  export const GL_DEPTH_CLEAR_VALUE = 0x0B73;

  export const GL_DEPTH_FUNC = 0x0B74;

  export const GL_STENCIL_CLEAR_VALUE = 0x0B91;

  export const GL_STENCIL_FUNC = 0x0B92;

  export const GL_STENCIL_FAIL = 0x0B94;

  export const GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;

  export const GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;

  export const GL_STENCIL_REF = 0x0B97;

  export const GL_STENCIL_VALUE_MASK = 0x0B93;

  export const GL_STENCIL_WRITEMASK = 0x0B98;

  export const GL_STENCIL_BACK_FUNC = 0x8800;

  export const GL_STENCIL_BACK_FAIL = 0x8801;

  export const GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;

  export const GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;

  export const GL_STENCIL_BACK_REF = 0x8CA3;

  export const GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;

  export const GL_STENCIL_BACK_WRITEMASK = 0x8CA5;

  export const GL_VIEWPORT = 0x0BA2;

  export const GL_SCISSOR_BOX = 0x0C10;

  export const GL_COLOR_CLEAR_VALUE = 0x0C22;

  export const GL_COLOR_WRITEMASK = 0x0C23;

  export const GL_UNPACK_ALIGNMENT = 0x0CF5;

  export const GL_PACK_ALIGNMENT = 0x0D05;

  export const GL_MAX_TEXTURE_SIZE = 0x0D33;

  export const GL_MAX_VIEWPORT_DIMS = 0x0D3A;

  export const GL_SUBPIXEL_BITS = 0x0D50;

  export const GL_RED_BITS = 0x0D52;

  export const GL_GREEN_BITS = 0x0D53;

  export const GL_BLUE_BITS = 0x0D54;

  export const GL_ALPHA_BITS = 0x0D55;

  export const GL_DEPTH_BITS = 0x0D56;

  export const GL_STENCIL_BITS = 0x0D57;

  export const GL_POLYGON_OFFSET_UNITS = 0x2A00;

  export const GL_POLYGON_OFFSET_FACTOR = 0x8038;

  export const GL_TEXTURE_BINDING_2D = 0x8069;

  export const GL_SAMPLE_BUFFERS = 0x80A8;

  export const GL_SAMPLES = 0x80A9;

  export const GL_SAMPLE_COVERAGE_VALUE = 0x80AA;

  export const GL_SAMPLE_COVERAGE_INVERT = 0x80AB;

  export const GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;

  export const GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;

  export const GL_DONT_CARE = 0x1100;

  export const GL_FASTEST = 0x1101;

  export const GL_NICEST = 0x1102;

  export const GL_GENERATE_MIPMAP_HINT = 0x8192;

  export const GL_BYTE = 0x1400;

  export const GL_UNSIGNED_BYTE = 0x1401;

  export const GL_SHORT = 0x1402;

  export const GL_UNSIGNED_SHORT = 0x1403;

  export const GL_INT = 0x1404;

  export const GL_UNSIGNED_INT = 0x1405;

  export const GL_FLOAT = 0x1406;

  export const GL_FIXED = 0x140C;

  export const GL_DEPTH_COMPONENT = 0x1902;

  export const GL_ALPHA = 0x1906;

  export const GL_RGB = 0x1907;

  export const GL_RGBA = 0x1908;

  export const GL_LUMINANCE = 0x1909;

  export const GL_LUMINANCE_ALPHA = 0x190A;

  export const GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;

  export const GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;

  export const GL_UNSIGNED_SHORT_5_6_5 = 0x8363;

  export const GL_FRAGMENT_SHADER = 0x8B30;

  export const GL_VERTEX_SHADER = 0x8B31;

  export const GL_MAX_VERTEX_ATTRIBS = 0x8869;

  export const GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;

  export const GL_MAX_VARYING_VECTORS = 0x8DFC;

  export const GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;

  export const GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;

  export const GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;

  export const GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;

  export const GL_SHADER_TYPE = 0x8B4F;

  export const GL_DELETE_STATUS = 0x8B80;

  export const GL_LINK_STATUS = 0x8B82;

  export const GL_VALIDATE_STATUS = 0x8B83;

  export const GL_ATTACHED_SHADERS = 0x8B85;

  export const GL_ACTIVE_UNIFORMS = 0x8B86;

  export const GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;

  export const GL_ACTIVE_ATTRIBUTES = 0x8B89;

  export const GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;

  export const GL_SHADING_LANGUAGE_VERSION = 0x8B8C;

  export const GL_CURRENT_PROGRAM = 0x8B8D;

  export const GL_NEVER = 0x0200;

  export const GL_LESS = 0x0201;

  export const GL_EQUAL = 0x0202;

  export const GL_LEQUAL = 0x0203;

  export const GL_GREATER = 0x0204;

  export const GL_NOTEQUAL = 0x0205;

  export const GL_GEQUAL = 0x0206;

  export const GL_ALWAYS = 0x0207;

  export const GL_KEEP = 0x1E00;

  export const GL_REPLACE = 0x1E01;

  export const GL_INCR = 0x1E02;

  export const GL_DECR = 0x1E03;

  export const GL_INVERT = 0x150A;

  export const GL_INCR_WRAP = 0x8507;

  export const GL_DECR_WRAP = 0x8508;

  export const GL_VENDOR = 0x1F00;

  export const GL_RENDERER = 0x1F01;

  export const GL_VERSION = 0x1F02;

  export const GL_EXTENSIONS = 0x1F03;

  export const GL_NEAREST = 0x2600;

  export const GL_LINEAR = 0x2601;

  export const GL_NEAREST_MIPMAP_NEAREST = 0x2700;

  export const GL_LINEAR_MIPMAP_NEAREST = 0x2701;

  export const GL_NEAREST_MIPMAP_LINEAR = 0x2702;

  export const GL_LINEAR_MIPMAP_LINEAR = 0x2703;

  export const GL_TEXTURE_MAG_FILTER = 0x2800;

  export const GL_TEXTURE_MIN_FILTER = 0x2801;

  export const GL_TEXTURE_WRAP_S = 0x2802;

  export const GL_TEXTURE_WRAP_T = 0x2803;

  export const GL_TEXTURE = 0x1702;

  export const GL_TEXTURE_CUBE_MAP = 0x8513;

  export const GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;

  export const GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;

  export const GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;

  export const GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;

  export const GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;

  export const GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;

  export const GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;

  export const GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;

  export const GL_TEXTURE0 = 0x84C0;

  export const GL_TEXTURE1 = 0x84C1;

  export const GL_TEXTURE2 = 0x84C2;

  export const GL_TEXTURE3 = 0x84C3;

  export const GL_TEXTURE4 = 0x84C4;

  export const GL_TEXTURE5 = 0x84C5;

  export const GL_TEXTURE6 = 0x84C6;

  export const GL_TEXTURE7 = 0x84C7;

  export const GL_TEXTURE8 = 0x84C8;

  export const GL_TEXTURE9 = 0x84C9;

  export const GL_TEXTURE10 = 0x84CA;

  export const GL_TEXTURE11 = 0x84CB;

  export const GL_TEXTURE12 = 0x84CC;

  export const GL_TEXTURE13 = 0x84CD;

  export const GL_TEXTURE14 = 0x84CE;

  export const GL_TEXTURE15 = 0x84CF;

  export const GL_TEXTURE16 = 0x84D0;

  export const GL_TEXTURE17 = 0x84D1;

  export const GL_TEXTURE18 = 0x84D2;

  export const GL_TEXTURE19 = 0x84D3;

  export const GL_TEXTURE20 = 0x84D4;

  export const GL_TEXTURE21 = 0x84D5;

  export const GL_TEXTURE22 = 0x84D6;

  export const GL_TEXTURE23 = 0x84D7;

  export const GL_TEXTURE24 = 0x84D8;

  export const GL_TEXTURE25 = 0x84D9;

  export const GL_TEXTURE26 = 0x84DA;

  export const GL_TEXTURE27 = 0x84DB;

  export const GL_TEXTURE28 = 0x84DC;

  export const GL_TEXTURE29 = 0x84DD;

  export const GL_TEXTURE30 = 0x84DE;

  export const GL_TEXTURE31 = 0x84DF;

  export const GL_ACTIVE_TEXTURE = 0x84E0;

  export const GL_REPEAT = 0x2901;

  export const GL_CLAMP_TO_EDGE = 0x812F;

  export const GL_MIRRORED_REPEAT = 0x8370;

  export const GL_FLOAT_VEC2 = 0x8B50;

  export const GL_FLOAT_VEC3 = 0x8B51;

  export const GL_FLOAT_VEC4 = 0x8B52;

  export const GL_INT_VEC2 = 0x8B53;

  export const GL_INT_VEC3 = 0x8B54;

  export const GL_INT_VEC4 = 0x8B55;

  export const GL_BOOL = 0x8B56;

  export const GL_BOOL_VEC2 = 0x8B57;

  export const GL_BOOL_VEC3 = 0x8B58;

  export const GL_BOOL_VEC4 = 0x8B59;

  export const GL_FLOAT_MAT2 = 0x8B5A;

  export const GL_FLOAT_MAT3 = 0x8B5B;

  export const GL_FLOAT_MAT4 = 0x8B5C;

  export const GL_SAMPLER_2D = 0x8B5E;

  export const GL_SAMPLER_CUBE = 0x8B60;

  export const GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;

  export const GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;

  export const GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;

  export const GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;

  export const GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;

  export const GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;

  export const GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;

  export const GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;

  export const GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;

  export const GL_COMPILE_STATUS = 0x8B81;

  export const GL_INFO_LOG_LENGTH = 0x8B84;

  export const GL_SHADER_SOURCE_LENGTH = 0x8B88;

  export const GL_SHADER_COMPILER = 0x8DFA;

  export const GL_SHADER_BINARY_FORMATS = 0x8DF8;

  export const GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9;

  export const GL_LOW_FLOAT = 0x8DF0;

  export const GL_MEDIUM_FLOAT = 0x8DF1;

  export const GL_HIGH_FLOAT = 0x8DF2;

  export const GL_LOW_INT = 0x8DF3;

  export const GL_MEDIUM_INT = 0x8DF4;

  export const GL_HIGH_INT = 0x8DF5;

  export const GL_FRAMEBUFFER = 0x8D40;

  export const GL_RENDERBUFFER = 0x8D41;

  export const GL_RGBA4 = 0x8056;

  export const GL_RGB5_A1 = 0x8057;

  export const GL_RGB565 = 0x8D62;

  export const GL_DEPTH_COMPONENT16 = 0x81A5;

  export const GL_STENCIL_INDEX8 = 0x8D48;

  export const GL_RENDERBUFFER_WIDTH = 0x8D42;

  export const GL_RENDERBUFFER_HEIGHT = 0x8D43;

  export const GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;

  export const GL_RENDERBUFFER_RED_SIZE = 0x8D50;

  export const GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;

  export const GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;

  export const GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;

  export const GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;

  export const GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;

  export const GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;

  export const GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;

  export const GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;

  export const GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;

  export const GL_COLOR_ATTACHMENT0 = 0x8CE0;

  export const GL_DEPTH_ATTACHMENT = 0x8D00;

  export const GL_STENCIL_ATTACHMENT = 0x8D20;

  export const GL_NONE = 0;

  export const GL_FRAMEBUFFER_COMPLETE = 0x8CD5;

  export const GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;

  export const GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;

  export const GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9;

  export const GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;

  export const GL_FRAMEBUFFER_BINDING = 0x8CA6;

  export const GL_RENDERBUFFER_BINDING = 0x8CA7;

  export const GL_MAX_RENDERBUFFER_SIZE = 0x84E8;

  export const GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;

  export const GL_READ_BUFFER = 0x0C02;

  export const GL_UNPACK_ROW_LENGTH = 0x0CF2;

  export const GL_UNPACK_SKIP_ROWS = 0x0CF3;

  export const GL_UNPACK_SKIP_PIXELS = 0x0CF4;

  export const GL_PACK_ROW_LENGTH = 0x0D02;

  export const GL_PACK_SKIP_ROWS = 0x0D03;

  export const GL_PACK_SKIP_PIXELS = 0x0D04;

  export const GL_COLOR = 0x1800;

  export const GL_DEPTH = 0x1801;

  export const GL_STENCIL = 0x1802;

  export const GL_RED = 0x1903;

  export const GL_RGB8 = 0x8051;

  export const GL_RGBA8 = 0x8058;

  export const GL_RGB10_A2 = 0x8059;

  export const GL_TEXTURE_BINDING_3D = 0x806A;

  export const GL_UNPACK_SKIP_IMAGES = 0x806D;

  export const GL_UNPACK_IMAGE_HEIGHT = 0x806E;

  export const GL_TEXTURE_3D = 0x806F;

  export const GL_TEXTURE_WRAP_R = 0x8072;

  export const GL_MAX_3D_TEXTURE_SIZE = 0x8073;

  export const GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;

  export const GL_MAX_ELEMENTS_VERTICES = 0x80E8;

  export const GL_MAX_ELEMENTS_INDICES = 0x80E9;

  export const GL_TEXTURE_MIN_LOD = 0x813A;

  export const GL_TEXTURE_MAX_LOD = 0x813B;

  export const GL_TEXTURE_BASE_LEVEL = 0x813C;

  export const GL_TEXTURE_MAX_LEVEL = 0x813D;

  export const GL_MIN = 0x8007;

  export const GL_MAX = 0x8008;

  export const GL_DEPTH_COMPONENT24 = 0x81A6;

  export const GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;

  export const GL_TEXTURE_COMPARE_MODE = 0x884C;

  export const GL_TEXTURE_COMPARE_FUNC = 0x884D;

  export const GL_CURRENT_QUERY = 0x8865;

  export const GL_QUERY_RESULT = 0x8866;

  export const GL_QUERY_RESULT_AVAILABLE = 0x8867;

  export const GL_BUFFER_MAPPED = 0x88BC;

  export const GL_BUFFER_MAP_POINTER = 0x88BD;

  export const GL_STREAM_READ = 0x88E1;

  export const GL_STREAM_COPY = 0x88E2;

  export const GL_STATIC_READ = 0x88E5;

  export const GL_STATIC_COPY = 0x88E6;

  export const GL_DYNAMIC_READ = 0x88E9;

  export const GL_DYNAMIC_COPY = 0x88EA;

  export const GL_MAX_DRAW_BUFFERS = 0x8824;

  export const GL_DRAW_BUFFER0 = 0x8825;

  export const GL_DRAW_BUFFER1 = 0x8826;

  export const GL_DRAW_BUFFER2 = 0x8827;

  export const GL_DRAW_BUFFER3 = 0x8828;

  export const GL_DRAW_BUFFER4 = 0x8829;

  export const GL_DRAW_BUFFER5 = 0x882A;

  export const GL_DRAW_BUFFER6 = 0x882B;

  export const GL_DRAW_BUFFER7 = 0x882C;

  export const GL_DRAW_BUFFER8 = 0x882D;

  export const GL_DRAW_BUFFER9 = 0x882E;

  export const GL_DRAW_BUFFER10 = 0x882F;

  export const GL_DRAW_BUFFER11 = 0x8830;

  export const GL_DRAW_BUFFER12 = 0x8831;

  export const GL_DRAW_BUFFER13 = 0x8832;

  export const GL_DRAW_BUFFER14 = 0x8833;

  export const GL_DRAW_BUFFER15 = 0x8834;

  export const GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;

  export const GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;

  export const GL_SAMPLER_3D = 0x8B5F;

  export const GL_SAMPLER_2D_SHADOW = 0x8B62;

  export const GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;

  export const GL_PIXEL_PACK_BUFFER = 0x88EB;

  export const GL_PIXEL_UNPACK_BUFFER = 0x88EC;

  export const GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;

  export const GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;

  export const GL_FLOAT_MAT2x3 = 0x8B65;

  export const GL_FLOAT_MAT2x4 = 0x8B66;

  export const GL_FLOAT_MAT3x2 = 0x8B67;

  export const GL_FLOAT_MAT3x4 = 0x8B68;

  export const GL_FLOAT_MAT4x2 = 0x8B69;

  export const GL_FLOAT_MAT4x3 = 0x8B6A;

  export const GL_SRGB = 0x8C40;

  export const GL_SRGB8 = 0x8C41;

  export const GL_SRGB8_ALPHA8 = 0x8C43;

  export const GL_COMPARE_REF_TO_TEXTURE = 0x884E;

  export const GL_MAJOR_VERSION = 0x821B;

  export const GL_MINOR_VERSION = 0x821C;

  export const GL_NUM_EXTENSIONS = 0x821D;

  export const GL_RGBA32F = 0x8814;

  export const GL_RGB32F = 0x8815;

  export const GL_RGBA16F = 0x881A;

  export const GL_RGB16F = 0x881B;

  export const GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;

  export const GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;

  export const GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;

  export const GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;

  export const GL_MAX_VARYING_COMPONENTS = 0x8B4B;

  export const GL_TEXTURE_2D_ARRAY = 0x8C1A;

  export const GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;

  export const GL_R11F_G11F_B10F = 0x8C3A;

  export const GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;

  export const GL_RGB9_E5 = 0x8C3D;

  export const GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;

  export const GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;

  export const GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;

  export const GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;

  export const GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;

  export const GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;

  export const GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;

  export const GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;

  export const GL_RASTERIZER_DISCARD = 0x8C89;

  export const GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;

  export const GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;

  export const GL_INTERLEAVED_ATTRIBS = 0x8C8C;

  export const GL_SEPARATE_ATTRIBS = 0x8C8D;

  export const GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;

  export const GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;

  export const GL_RGBA32UI = 0x8D70;

  export const GL_RGB32UI = 0x8D71;

  export const GL_RGBA16UI = 0x8D76;

  export const GL_RGB16UI = 0x8D77;

  export const GL_RGBA8UI = 0x8D7C;

  export const GL_RGB8UI = 0x8D7D;

  export const GL_RGBA32I = 0x8D82;

  export const GL_RGB32I = 0x8D83;

  export const GL_RGBA16I = 0x8D88;

  export const GL_RGB16I = 0x8D89;

  export const GL_RGBA8I = 0x8D8E;

  export const GL_RGB8I = 0x8D8F;

  export const GL_RED_INTEGER = 0x8D94;

  export const GL_RGB_INTEGER = 0x8D98;

  export const GL_RGBA_INTEGER = 0x8D99;

  export const GL_SAMPLER_2D_ARRAY = 0x8DC1;

  export const GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;

  export const GL_SAMPLER_CUBE_SHADOW = 0x8DC5;

  export const GL_UNSIGNED_INT_VEC2 = 0x8DC6;

  export const GL_UNSIGNED_INT_VEC3 = 0x8DC7;

  export const GL_UNSIGNED_INT_VEC4 = 0x8DC8;

  export const GL_INT_SAMPLER_2D = 0x8DCA;

  export const GL_INT_SAMPLER_3D = 0x8DCB;

  export const GL_INT_SAMPLER_CUBE = 0x8DCC;

  export const GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;

  export const GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;

  export const GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;

  export const GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;

  export const GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;

  export const GL_BUFFER_ACCESS_FLAGS = 0x911F;

  export const GL_BUFFER_MAP_LENGTH = 0x9120;

  export const GL_BUFFER_MAP_OFFSET = 0x9121;

  export const GL_DEPTH_COMPONENT32F = 0x8CAC;

  export const GL_DEPTH32F_STENCIL8 = 0x8CAD;

  export const GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;

  export const GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;

  export const GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;

  export const GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;

  export const GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;

  export const GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;

  export const GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;

  export const GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;

  export const GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;

  export const GL_FRAMEBUFFER_DEFAULT = 0x8218;

  export const GL_FRAMEBUFFER_UNDEFINED = 0x8219;

  export const GL_DEPTH_STENCIL_ATTACHMENT = 0x821A;

  export const GL_DEPTH_STENCIL = 0x84F9;

  export const GL_UNSIGNED_INT_24_8 = 0x84FA;

  export const GL_DEPTH24_STENCIL8 = 0x88F0;

  export const GL_UNSIGNED_NORMALIZED = 0x8C17;

  export const GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6;

  export const GL_READ_FRAMEBUFFER = 0x8CA8;

  export const GL_DRAW_FRAMEBUFFER = 0x8CA9;

  export const GL_READ_FRAMEBUFFER_BINDING = 0x8CAA;

  export const GL_RENDERBUFFER_SAMPLES = 0x8CAB;

  export const GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;

  export const GL_MAX_COLOR_ATTACHMENTS = 0x8CDF;

  export const GL_COLOR_ATTACHMENT1 = 0x8CE1;

  export const GL_COLOR_ATTACHMENT2 = 0x8CE2;

  export const GL_COLOR_ATTACHMENT3 = 0x8CE3;

  export const GL_COLOR_ATTACHMENT4 = 0x8CE4;

  export const GL_COLOR_ATTACHMENT5 = 0x8CE5;

  export const GL_COLOR_ATTACHMENT6 = 0x8CE6;

  export const GL_COLOR_ATTACHMENT7 = 0x8CE7;

  export const GL_COLOR_ATTACHMENT8 = 0x8CE8;

  export const GL_COLOR_ATTACHMENT9 = 0x8CE9;

  export const GL_COLOR_ATTACHMENT10 = 0x8CEA;

  export const GL_COLOR_ATTACHMENT11 = 0x8CEB;

  export const GL_COLOR_ATTACHMENT12 = 0x8CEC;

  export const GL_COLOR_ATTACHMENT13 = 0x8CED;

  export const GL_COLOR_ATTACHMENT14 = 0x8CEE;

  export const GL_COLOR_ATTACHMENT15 = 0x8CEF;

  export const GL_COLOR_ATTACHMENT16 = 0x8CF0;

  export const GL_COLOR_ATTACHMENT17 = 0x8CF1;

  export const GL_COLOR_ATTACHMENT18 = 0x8CF2;

  export const GL_COLOR_ATTACHMENT19 = 0x8CF3;

  export const GL_COLOR_ATTACHMENT20 = 0x8CF4;

  export const GL_COLOR_ATTACHMENT21 = 0x8CF5;

  export const GL_COLOR_ATTACHMENT22 = 0x8CF6;

  export const GL_COLOR_ATTACHMENT23 = 0x8CF7;

  export const GL_COLOR_ATTACHMENT24 = 0x8CF8;

  export const GL_COLOR_ATTACHMENT25 = 0x8CF9;

  export const GL_COLOR_ATTACHMENT26 = 0x8CFA;

  export const GL_COLOR_ATTACHMENT27 = 0x8CFB;

  export const GL_COLOR_ATTACHMENT28 = 0x8CFC;

  export const GL_COLOR_ATTACHMENT29 = 0x8CFD;

  export const GL_COLOR_ATTACHMENT30 = 0x8CFE;

  export const GL_COLOR_ATTACHMENT31 = 0x8CFF;

  export const GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;

  export const GL_MAX_SAMPLES = 0x8D57;

  export const GL_HALF_FLOAT = 0x140B;

  export const GL_MAP_READ_BIT = 0x0001;

  export const GL_MAP_WRITE_BIT = 0x0002;

  export const GL_MAP_INVALIDATE_RANGE_BIT = 0x0004;

  export const GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008;

  export const GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010;

  export const GL_MAP_UNSYNCHRONIZED_BIT = 0x0020;

  export const GL_RG = 0x8227;

  export const GL_RG_INTEGER = 0x8228;

  export const GL_R8 = 0x8229;

  export const GL_RG8 = 0x822B;

  export const GL_R16F = 0x822D;

  export const GL_R32F = 0x822E;

  export const GL_RG16F = 0x822F;

  export const GL_RG32F = 0x8230;

  export const GL_R8I = 0x8231;

  export const GL_R8UI = 0x8232;

  export const GL_R16I = 0x8233;

  export const GL_R16UI = 0x8234;

  export const GL_R32I = 0x8235;

  export const GL_R32UI = 0x8236;

  export const GL_RG8I = 0x8237;

  export const GL_RG8UI = 0x8238;

  export const GL_RG16I = 0x8239;

  export const GL_RG16UI = 0x823A;

  export const GL_RG32I = 0x823B;

  export const GL_RG32UI = 0x823C;

  export const GL_VERTEX_ARRAY_BINDING = 0x85B5;

  export const GL_R8_SNORM = 0x8F94;

  export const GL_RG8_SNORM = 0x8F95;

  export const GL_RGB8_SNORM = 0x8F96;

  export const GL_RGBA8_SNORM = 0x8F97;

  export const GL_SIGNED_NORMALIZED = 0x8F9C;

  export const GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69;

  export const GL_COPY_READ_BUFFER = 0x8F36;

  export const GL_COPY_WRITE_BUFFER = 0x8F37;

  export const GL_COPY_READ_BUFFER_BINDING = 0x8F36;

  export const GL_COPY_WRITE_BUFFER_BINDING = 0x8F37;

  export const GL_UNIFORM_BUFFER = 0x8A11;

  export const GL_UNIFORM_BUFFER_BINDING = 0x8A28;

  export const GL_UNIFORM_BUFFER_START = 0x8A29;

  export const GL_UNIFORM_BUFFER_SIZE = 0x8A2A;

  export const GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;

  export const GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;

  export const GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;

  export const GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;

  export const GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30;

  export const GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;

  export const GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;

  export const GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;

  export const GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;

  export const GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36;

  export const GL_UNIFORM_TYPE = 0x8A37;

  export const GL_UNIFORM_SIZE = 0x8A38;

  export const GL_UNIFORM_NAME_LENGTH = 0x8A39;

  export const GL_UNIFORM_BLOCK_INDEX = 0x8A3A;

  export const GL_UNIFORM_OFFSET = 0x8A3B;

  export const GL_UNIFORM_ARRAY_STRIDE = 0x8A3C;

  export const GL_UNIFORM_MATRIX_STRIDE = 0x8A3D;

  export const GL_UNIFORM_IS_ROW_MAJOR = 0x8A3E;

  export const GL_UNIFORM_BLOCK_BINDING = 0x8A3F;

  export const GL_UNIFORM_BLOCK_DATA_SIZE = 0x8A40;

  export const GL_UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;

  export const GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;

  export const GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;

  export const GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;

  export const GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;

  export const GL_INVALID_INDEX = 0xFFFFFFFF;

  export const GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;

  export const GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;

  export const GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111;

  export const GL_OBJECT_TYPE = 0x9112;

  export const GL_SYNC_CONDITION = 0x9113;

  export const GL_SYNC_STATUS = 0x9114;

  export const GL_SYNC_FLAGS = 0x9115;

  export const GL_SYNC_FENCE = 0x9116;

  export const GL_SYNC_GPU_COMMANDS_COMPLETE = 0x9117;

  export const GL_UNSIGNALED = 0x9118;

  export const GL_SIGNALED = 0x9119;

  export const GL_ALREADY_SIGNALED = 0x911A;

  export const GL_TIMEOUT_EXPIRED = 0x911B;

  export const GL_CONDITION_SATISFIED = 0x911C;

  export const GL_WAIT_FAILED = 0x911D;

  export const GL_SYNC_FLUSH_COMMANDS_BIT = 0x00000001;

  export const GL_TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;

  export const GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;

  export const GL_ANY_SAMPLES_PASSED = 0x8C2F;

  export const GL_ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A;

  export const GL_SAMPLER_BINDING = 0x8919;

  export const GL_RGB10_A2UI = 0x906F;

  export const GL_TEXTURE_SWIZZLE_R = 0x8E42;

  export const GL_TEXTURE_SWIZZLE_G = 0x8E43;

  export const GL_TEXTURE_SWIZZLE_B = 0x8E44;

  export const GL_TEXTURE_SWIZZLE_A = 0x8E45;

  export const GL_GREEN = 0x1904;

  export const GL_BLUE = 0x1905;

  export const GL_INT_2_10_10_10_REV = 0x8D9F;

  export const GL_TRANSFORM_FEEDBACK = 0x8E22;

  export const GL_TRANSFORM_FEEDBACK_PAUSED = 0x8E23;

  export const GL_TRANSFORM_FEEDBACK_ACTIVE = 0x8E24;

  export const GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25;

  export const GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257;

  export const GL_PROGRAM_BINARY_LENGTH = 0x8741;

  export const GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE;

  export const GL_PROGRAM_BINARY_FORMATS = 0x87FF;

  export const GL_COMPRESSED_R11_EAC = 0x9270;

  export const GL_COMPRESSED_SIGNED_R11_EAC = 0x9271;

  export const GL_COMPRESSED_RG11_EAC = 0x9272;

  export const GL_COMPRESSED_SIGNED_RG11_EAC = 0x9273;

  export const GL_COMPRESSED_RGB8_ETC2 = 0x9274;

  export const GL_COMPRESSED_SRGB8_ETC2 = 0x9275;

  export const GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276;

  export const GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277;

  export const GL_COMPRESSED_RGBA8_ETC2_EAC = 0x9278;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279;

  export const GL_TEXTURE_IMMUTABLE_FORMAT = 0x912F;

  export const GL_MAX_ELEMENT_INDEX = 0x8D6B;

  export const GL_NUM_SAMPLE_COUNTS = 0x9380;

  export const GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF;

  export const GL_COMPUTE_SHADER = 0x91B9;

  export const GL_MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;

  export const GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;

  export const GL_MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;

  export const GL_MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;

  export const GL_MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;

  export const GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;

  export const GL_MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;

  export const GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;

  export const GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;

  export const GL_MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;

  export const GL_MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;

  export const GL_COMPUTE_WORK_GROUP_SIZE = 0x8267;

  export const GL_DISPATCH_INDIRECT_BUFFER = 0x90EE;

  export const GL_DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;

  export const GL_COMPUTE_SHADER_BIT = 0x00000020;

  export const GL_DRAW_INDIRECT_BUFFER = 0x8F3F;

  export const GL_DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;

  export const GL_MAX_UNIFORM_LOCATIONS = 0x826E;

  export const GL_FRAMEBUFFER_DEFAULT_WIDTH = 0x9310;

  export const GL_FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311;

  export const GL_FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313;

  export const GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314;

  export const GL_MAX_FRAMEBUFFER_WIDTH = 0x9315;

  export const GL_MAX_FRAMEBUFFER_HEIGHT = 0x9316;

  export const GL_MAX_FRAMEBUFFER_SAMPLES = 0x9318;

  export const GL_UNIFORM = 0x92E1;

  export const GL_UNIFORM_BLOCK = 0x92E2;

  export const GL_PROGRAM_INPUT = 0x92E3;

  export const GL_PROGRAM_OUTPUT = 0x92E4;

  export const GL_BUFFER_VARIABLE = 0x92E5;

  export const GL_SHADER_STORAGE_BLOCK = 0x92E6;

  export const GL_ATOMIC_COUNTER_BUFFER = 0x92C0;

  export const GL_TRANSFORM_FEEDBACK_VARYING = 0x92F4;

  export const GL_ACTIVE_RESOURCES = 0x92F5;

  export const GL_MAX_NAME_LENGTH = 0x92F6;

  export const GL_MAX_NUM_ACTIVE_VARIABLES = 0x92F7;

  export const GL_NAME_LENGTH = 0x92F9;

  export const GL_TYPE = 0x92FA;

  export const GL_ARRAY_SIZE = 0x92FB;

  export const GL_OFFSET = 0x92FC;

  export const GL_BLOCK_INDEX = 0x92FD;

  export const GL_ARRAY_STRIDE = 0x92FE;

  export const GL_MATRIX_STRIDE = 0x92FF;

  export const GL_IS_ROW_MAJOR = 0x9300;

  export const GL_ATOMIC_COUNTER_BUFFER_INDEX = 0x9301;

  export const GL_BUFFER_BINDING = 0x9302;

  export const GL_BUFFER_DATA_SIZE = 0x9303;

  export const GL_NUM_ACTIVE_VARIABLES = 0x9304;

  export const GL_ACTIVE_VARIABLES = 0x9305;

  export const GL_REFERENCED_BY_VERTEX_SHADER = 0x9306;

  export const GL_REFERENCED_BY_FRAGMENT_SHADER = 0x930A;

  export const GL_REFERENCED_BY_COMPUTE_SHADER = 0x930B;

  export const GL_TOP_LEVEL_ARRAY_SIZE = 0x930C;

  export const GL_TOP_LEVEL_ARRAY_STRIDE = 0x930D;

  export const GL_LOCATION = 0x930E;

  export const GL_VERTEX_SHADER_BIT = 0x00000001;

  export const GL_FRAGMENT_SHADER_BIT = 0x00000002;

  export const GL_ALL_SHADER_BITS = 0xFFFFFFFF;

  export const GL_PROGRAM_SEPARABLE = 0x8258;

  export const GL_ACTIVE_PROGRAM = 0x8259;

  export const GL_PROGRAM_PIPELINE_BINDING = 0x825A;

  export const GL_ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1;

  export const GL_ATOMIC_COUNTER_BUFFER_START = 0x92C2;

  export const GL_ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3;

  export const GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC;

  export const GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0;

  export const GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1;

  export const GL_MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2;

  export const GL_MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6;

  export const GL_MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7;

  export const GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8;

  export const GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC;

  export const GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9;

  export const GL_UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;

  export const GL_MAX_IMAGE_UNITS = 0x8F38;

  export const GL_MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA;

  export const GL_MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE;

  export const GL_MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF;

  export const GL_IMAGE_BINDING_NAME = 0x8F3A;

  export const GL_IMAGE_BINDING_LEVEL = 0x8F3B;

  export const GL_IMAGE_BINDING_LAYERED = 0x8F3C;

  export const GL_IMAGE_BINDING_LAYER = 0x8F3D;

  export const GL_IMAGE_BINDING_ACCESS = 0x8F3E;

  export const GL_IMAGE_BINDING_FORMAT = 0x906E;

  export const GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001;

  export const GL_ELEMENT_ARRAY_BARRIER_BIT = 0x00000002;

  export const GL_UNIFORM_BARRIER_BIT = 0x00000004;

  export const GL_TEXTURE_FETCH_BARRIER_BIT = 0x00000008;

  export const GL_SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020;

  export const GL_COMMAND_BARRIER_BIT = 0x00000040;

  export const GL_PIXEL_BUFFER_BARRIER_BIT = 0x00000080;

  export const GL_TEXTURE_UPDATE_BARRIER_BIT = 0x00000100;

  export const GL_BUFFER_UPDATE_BARRIER_BIT = 0x00000200;

  export const GL_FRAMEBUFFER_BARRIER_BIT = 0x00000400;

  export const GL_TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800;

  export const GL_ATOMIC_COUNTER_BARRIER_BIT = 0x00001000;

  export const GL_ALL_BARRIER_BITS = 0xFFFFFFFF;

  export const GL_IMAGE_2D = 0x904D;

  export const GL_IMAGE_3D = 0x904E;

  export const GL_IMAGE_CUBE = 0x9050;

  export const GL_IMAGE_2D_ARRAY = 0x9053;

  export const GL_INT_IMAGE_2D = 0x9058;

  export const GL_INT_IMAGE_3D = 0x9059;

  export const GL_INT_IMAGE_CUBE = 0x905B;

  export const GL_INT_IMAGE_2D_ARRAY = 0x905E;

  export const GL_UNSIGNED_INT_IMAGE_2D = 0x9063;

  export const GL_UNSIGNED_INT_IMAGE_3D = 0x9064;

  export const GL_UNSIGNED_INT_IMAGE_CUBE = 0x9066;

  export const GL_UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;

  export const GL_IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7;

  export const GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8;

  export const GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9;

  export const GL_READ_ONLY = 0x88B8;

  export const GL_WRITE_ONLY = 0x88B9;

  export const GL_READ_WRITE = 0x88BA;

  export const GL_SHADER_STORAGE_BUFFER = 0x90D2;

  export const GL_SHADER_STORAGE_BUFFER_BINDING = 0x90D3;

  export const GL_SHADER_STORAGE_BUFFER_START = 0x90D4;

  export const GL_SHADER_STORAGE_BUFFER_SIZE = 0x90D5;

  export const GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6;

  export const GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA;

  export const GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB;

  export const GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC;

  export const GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD;

  export const GL_MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE;

  export const GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF;

  export const GL_SHADER_STORAGE_BARRIER_BIT = 0x00002000;

  export const GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39;

  export const GL_DEPTH_STENCIL_TEXTURE_MODE = 0x90EA;

  export const GL_STENCIL_INDEX = 0x1901;

  export const GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;

  export const GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;

  export const GL_SAMPLE_POSITION = 0x8E50;

  export const GL_SAMPLE_MASK = 0x8E51;

  export const GL_SAMPLE_MASK_VALUE = 0x8E52;

  export const GL_TEXTURE_2D_MULTISAMPLE = 0x9100;

  export const GL_MAX_SAMPLE_MASK_WORDS = 0x8E59;

  export const GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E;

  export const GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;

  export const GL_MAX_INTEGER_SAMPLES = 0x9110;

  export const GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;

  export const GL_TEXTURE_SAMPLES = 0x9106;

  export const GL_TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;

  export const GL_TEXTURE_WIDTH = 0x1000;

  export const GL_TEXTURE_HEIGHT = 0x1001;

  export const GL_TEXTURE_DEPTH = 0x8071;

  export const GL_TEXTURE_INTERNAL_FORMAT = 0x1003;

  export const GL_TEXTURE_RED_SIZE = 0x805C;

  export const GL_TEXTURE_GREEN_SIZE = 0x805D;

  export const GL_TEXTURE_BLUE_SIZE = 0x805E;

  export const GL_TEXTURE_ALPHA_SIZE = 0x805F;

  export const GL_TEXTURE_DEPTH_SIZE = 0x884A;

  export const GL_TEXTURE_STENCIL_SIZE = 0x88F1;

  export const GL_TEXTURE_SHARED_SIZE = 0x8C3F;

  export const GL_TEXTURE_RED_TYPE = 0x8C10;

  export const GL_TEXTURE_GREEN_TYPE = 0x8C11;

  export const GL_TEXTURE_BLUE_TYPE = 0x8C12;

  export const GL_TEXTURE_ALPHA_TYPE = 0x8C13;

  export const GL_TEXTURE_DEPTH_TYPE = 0x8C16;

  export const GL_TEXTURE_COMPRESSED = 0x86A1;

  export const GL_SAMPLER_2D_MULTISAMPLE = 0x9108;

  export const GL_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;

  export const GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;

  export const GL_VERTEX_ATTRIB_BINDING = 0x82D4;

  export const GL_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5;

  export const GL_VERTEX_BINDING_DIVISOR = 0x82D6;

  export const GL_VERTEX_BINDING_OFFSET = 0x82D7;

  export const GL_VERTEX_BINDING_STRIDE = 0x82D8;

  export const GL_VERTEX_BINDING_BUFFER = 0x8F4F;

  export const GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9;

  export const GL_MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA;

  export const GL_MAX_VERTEX_ATTRIB_STRIDE = 0x82E5;

  export const GL_MULTISAMPLE_LINE_WIDTH_RANGE = 0x9381;

  export const GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY = 0x9382;

  export const GL_MULTIPLY = 0x9294;

  export const GL_SCREEN = 0x9295;

  export const GL_OVERLAY = 0x9296;

  export const GL_DARKEN = 0x9297;

  export const GL_LIGHTEN = 0x9298;

  export const GL_COLORDODGE = 0x9299;

  export const GL_COLORBURN = 0x929A;

  export const GL_HARDLIGHT = 0x929B;

  export const GL_SOFTLIGHT = 0x929C;

  export const GL_DIFFERENCE = 0x929E;

  export const GL_EXCLUSION = 0x92A0;

  export const GL_HSL_HUE = 0x92AD;

  export const GL_HSL_SATURATION = 0x92AE;

  export const GL_HSL_COLOR = 0x92AF;

  export const GL_HSL_LUMINOSITY = 0x92B0;

  export const GL_DEBUG_OUTPUT_SYNCHRONOUS = 0x8242;

  export const GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243;

  export const GL_DEBUG_CALLBACK_FUNCTION = 0x8244;

  export const GL_DEBUG_CALLBACK_USER_PARAM = 0x8245;

  export const GL_DEBUG_SOURCE_API = 0x8246;

  export const GL_DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247;

  export const GL_DEBUG_SOURCE_SHADER_COMPILER = 0x8248;

  export const GL_DEBUG_SOURCE_THIRD_PARTY = 0x8249;

  export const GL_DEBUG_SOURCE_APPLICATION = 0x824A;

  export const GL_DEBUG_SOURCE_OTHER = 0x824B;

  export const GL_DEBUG_TYPE_ERROR = 0x824C;

  export const GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D;

  export const GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E;

  export const GL_DEBUG_TYPE_PORTABILITY = 0x824F;

  export const GL_DEBUG_TYPE_PERFORMANCE = 0x8250;

  export const GL_DEBUG_TYPE_OTHER = 0x8251;

  export const GL_DEBUG_TYPE_MARKER = 0x8268;

  export const GL_DEBUG_TYPE_PUSH_GROUP = 0x8269;

  export const GL_DEBUG_TYPE_POP_GROUP = 0x826A;

  export const GL_DEBUG_SEVERITY_NOTIFICATION = 0x826B;

  export const GL_MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C;

  export const GL_DEBUG_GROUP_STACK_DEPTH = 0x826D;

  export const GL_BUFFER = 0x82E0;

  export const GL_SHADER = 0x82E1;

  export const GL_PROGRAM = 0x82E2;

  export const GL_VERTEX_ARRAY = 0x8074;

  export const GL_QUERY = 0x82E3;

  export const GL_PROGRAM_PIPELINE = 0x82E4;

  export const GL_SAMPLER = 0x82E6;

  export const GL_MAX_LABEL_LENGTH = 0x82E8;

  export const GL_MAX_DEBUG_MESSAGE_LENGTH = 0x9143;

  export const GL_MAX_DEBUG_LOGGED_MESSAGES = 0x9144;

  export const GL_DEBUG_LOGGED_MESSAGES = 0x9145;

  export const GL_DEBUG_SEVERITY_HIGH = 0x9146;

  export const GL_DEBUG_SEVERITY_MEDIUM = 0x9147;

  export const GL_DEBUG_SEVERITY_LOW = 0x9148;

  export const GL_DEBUG_OUTPUT = 0x92E0;

  export const GL_CONTEXT_FLAG_DEBUG_BIT = 0x00000002;

  export const GL_STACK_OVERFLOW = 0x0503;

  export const GL_STACK_UNDERFLOW = 0x0504;

  export const GL_GEOMETRY_SHADER = 0x8DD9;

  export const GL_GEOMETRY_SHADER_BIT = 0x00000004;

  export const GL_GEOMETRY_VERTICES_OUT = 0x8916;

  export const GL_GEOMETRY_INPUT_TYPE = 0x8917;

  export const GL_GEOMETRY_OUTPUT_TYPE = 0x8918;

  export const GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F;

  export const GL_LAYER_PROVOKING_VERTEX = 0x825E;

  export const GL_LINES_ADJACENCY = 0x000A;

  export const GL_LINE_STRIP_ADJACENCY = 0x000B;

  export const GL_TRIANGLES_ADJACENCY = 0x000C;

  export const GL_TRIANGLE_STRIP_ADJACENCY = 0x000D;

  export const GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;

  export const GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;

  export const GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;

  export const GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;

  export const GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;

  export const GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;

  export const GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;

  export const GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;

  export const GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;

  export const GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF;

  export const GL_MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5;

  export const GL_MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD;

  export const GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7;

  export const GL_FIRST_VERTEX_CONVENTION = 0x8E4D;

  export const GL_LAST_VERTEX_CONVENTION = 0x8E4E;

  export const GL_UNDEFINED_VERTEX = 0x8260;

  export const GL_PRIMITIVES_GENERATED = 0x8C87;

  export const GL_FRAMEBUFFER_DEFAULT_LAYERS = 0x9312;

  export const GL_MAX_FRAMEBUFFER_LAYERS = 0x9317;

  export const GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;

  export const GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;

  export const GL_REFERENCED_BY_GEOMETRY_SHADER = 0x9309;

  export const GL_PRIMITIVE_BOUNDING_BOX = 0x92BE;

  export const GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004;

  export const GL_CONTEXT_FLAGS = 0x821E;

  export const GL_LOSE_CONTEXT_ON_RESET = 0x8252;

  export const GL_GUILTY_CONTEXT_RESET = 0x8253;

  export const GL_INNOCENT_CONTEXT_RESET = 0x8254;

  export const GL_UNKNOWN_CONTEXT_RESET = 0x8255;

  export const GL_RESET_NOTIFICATION_STRATEGY = 0x8256;

  export const GL_NO_RESET_NOTIFICATION = 0x8261;

  export const GL_CONTEXT_LOST = 0x0507;

  export const GL_SAMPLE_SHADING = 0x8C36;

  export const GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37;

  export const GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;

  export const GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;

  export const GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;

  export const GL_PATCHES = 0x000E;

  export const GL_PATCH_VERTICES = 0x8E72;

  export const GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;

  export const GL_TESS_GEN_MODE = 0x8E76;

  export const GL_TESS_GEN_SPACING = 0x8E77;

  export const GL_TESS_GEN_VERTEX_ORDER = 0x8E78;

  export const GL_TESS_GEN_POINT_MODE = 0x8E79;

  export const GL_ISOLINES = 0x8E7A;

  export const GL_QUADS = 0x0007;

  export const GL_FRACTIONAL_ODD = 0x8E7B;

  export const GL_FRACTIONAL_EVEN = 0x8E7C;

  export const GL_MAX_PATCH_VERTICES = 0x8E7D;

  export const GL_MAX_TESS_GEN_LEVEL = 0x8E7E;

  export const GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;

  export const GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;

  export const GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;

  export const GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;

  export const GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;

  export const GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84;

  export const GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;

  export const GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;

  export const GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;

  export const GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;

  export const GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;

  export const GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;

  export const GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;

  export const GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;

  export const GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD;

  export const GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE;

  export const GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3;

  export const GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4;

  export const GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB;

  export const GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC;

  export const GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8;

  export const GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9;

  export const GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;

  export const GL_IS_PER_PATCH = 0x92E7;

  export const GL_REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307;

  export const GL_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308;

  export const GL_TESS_CONTROL_SHADER = 0x8E88;

  export const GL_TESS_EVALUATION_SHADER = 0x8E87;

  export const GL_TESS_CONTROL_SHADER_BIT = 0x00000008;

  export const GL_TESS_EVALUATION_SHADER_BIT = 0x00000010;

  export const GL_TEXTURE_BORDER_COLOR = 0x1004;

  export const GL_CLAMP_TO_BORDER = 0x812D;

  export const GL_TEXTURE_BUFFER = 0x8C2A;

  export const GL_TEXTURE_BUFFER_BINDING = 0x8C2A;

  export const GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;

  export const GL_TEXTURE_BINDING_BUFFER = 0x8C2C;

  export const GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;

  export const GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F;

  export const GL_SAMPLER_BUFFER = 0x8DC2;

  export const GL_INT_SAMPLER_BUFFER = 0x8DD0;

  export const GL_UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;

  export const GL_IMAGE_BUFFER = 0x9051;

  export const GL_INT_IMAGE_BUFFER = 0x905C;

  export const GL_UNSIGNED_INT_IMAGE_BUFFER = 0x9067;

  export const GL_TEXTURE_BUFFER_OFFSET = 0x919D;

  export const GL_TEXTURE_BUFFER_SIZE = 0x919E;

  export const GL_COMPRESSED_RGBA_ASTC_4x4 = 0x93B0;

  export const GL_COMPRESSED_RGBA_ASTC_5x4 = 0x93B1;

  export const GL_COMPRESSED_RGBA_ASTC_5x5 = 0x93B2;

  export const GL_COMPRESSED_RGBA_ASTC_6x5 = 0x93B3;

  export const GL_COMPRESSED_RGBA_ASTC_6x6 = 0x93B4;

  export const GL_COMPRESSED_RGBA_ASTC_8x5 = 0x93B5;

  export const GL_COMPRESSED_RGBA_ASTC_8x6 = 0x93B6;

  export const GL_COMPRESSED_RGBA_ASTC_8x8 = 0x93B7;

  export const GL_COMPRESSED_RGBA_ASTC_10x5 = 0x93B8;

  export const GL_COMPRESSED_RGBA_ASTC_10x6 = 0x93B9;

  export const GL_COMPRESSED_RGBA_ASTC_10x8 = 0x93BA;

  export const GL_COMPRESSED_RGBA_ASTC_10x10 = 0x93BB;

  export const GL_COMPRESSED_RGBA_ASTC_12x10 = 0x93BC;

  export const GL_COMPRESSED_RGBA_ASTC_12x12 = 0x93BD;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4 = 0x93D0;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4 = 0x93D1;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5 = 0x93D2;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5 = 0x93D3;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6 = 0x93D4;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5 = 0x93D5;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6 = 0x93D6;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8 = 0x93D7;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5 = 0x93D8;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6 = 0x93D9;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8 = 0x93DA;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10 = 0x93DB;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10 = 0x93DC;

  export const GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12 = 0x93DD;

  export const GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;

  export const GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;

  export const GL_SAMPLER_CUBE_MAP_ARRAY = 0x900C;

  export const GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;

  export const GL_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;

  export const GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;

  export const GL_IMAGE_CUBE_MAP_ARRAY = 0x9054;

  export const GL_INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;

  export const GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;

  export const GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;

  export const GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;

  export const GL_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;

  export const GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;

  export const GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;

  /**
   * @since 0.2.0
   * @description Buffer 可用作vbo、ibo等
   */
  export class Buffer {
    constructor(target?: BufferType)

    /**
     * @returns buffer handle
     */
    get id(): number

    /**
     * @returns buffer type
     */
    get bufferType(): BufferType

    /**
     * 绑定buffer
     */
    bind(): void

    /**
     * 解绑buffer
     */
    unbind(): void

    /**
     * @param data such as Uint8Array、Uint32Array
     * @param usage {BufferUsage}
     */
    setData(data: ArrayLike<number>, usage: BufferUsage): void

    /**
     * update buffer
     * @param data
     * @param offset
     */
    setSubData(data: ArrayLike<number>, offset: number): void;

    getParameter(pname: BufferParamName): number

    getParameter64(pname: BufferParamName): number

    delete(): void
  }

  /**
   * @since 0.2.0
   * @description opengl program
   */
  export class Program {
    constructor()

    /**
     * program handle
     */
    get id(): number

    /**
     * 获取program连接信息
     */
    get infoLog(): string

    /**
     * 获取已激活的attribute数量
     */
    get activeAttributes(): number

    /**
     * 获取已激活的uniform数量
     */
    get activeUniforms(): number

    get activeAttributeMaxLength(): number

    get activeUniformMaxLength(): number

    /**
     * 使用program
     */
    bind(): void;

    /**
     * 解绑program
     */
    unbind(): void

    /**
     * 编译shader和连接program
     */
    attach(...args: Shader[]): boolean

    detach(...args: Shader[]): void;

    setUniformf<T extends vec>(name: string, vec: T): void

    setUniformf(name: string, v0: number): void

    setUniformf(name: string, v0: number, v1: number): void

    setUniformf(name: string, v0: number, v1: number, v2: number): void

    setUniformf(name: string, v0: number, v1: number, v2: number, v3: number): void

    setUniformi<T extends ivec>(name: string, ivec: T): void

    setUniformi(name: string, v0: number): void

    setUniformi(name: string, v0: number, v1: number): void

    setUniformi(name: string, v0: number, v1: number, v2: number): void

    setUniformi(name: string, v0: number, v1: number, v2: number, v3: number): void

    setUniformi<T extends ivec>(name: string, value: T | number, v1?: number, v2?: number, v3?: number): void

    getUniformLocation(name: string): number

    delete(): boolean
  }

  /**
   * @since 0.2.0
   * opengl shader封装
   */
  export class Shader {
    constructor(type: ShaderType)

    /**
     * 通过uri获取文件并载入着色器对象中
     */
    static fromUri(type: ShaderType, uri: string, encoding?: string): Shader

    /**
     * 生成一个着色器并载入source
     */
    static fromString(type: ShaderType, source: string): Shader

    /**
     * 获取shader handle
     */
    get id(): number

    /**
     * 着色器编译结果
     */
    get infoLog(): string

    /**
     * 是否编译成功
     */
    get isCompiled(): boolean

    /**
     * 编译着色器
     */
    compile(): boolean

    /**
     * 删除着色器
     */
    delete(): boolean
  }

  interface vec {}

  interface ivec {}

  export class vec2 implements vec {
    constructor(scalar: number)

    constructor(x: number, y: number)

    get x(): number

    get y(): number
  }

  export class vec3 implements vec {
    constructor(scalar: number)

    constructor(x: number, y: number, z: number)

    get x(): number

    get y(): number

    get z(): number
  }

  export class vec4 implements vec {
    constructor(scalar: number)

    constructor(x: number, y: number, z: number, w: number)

    get x(): number

    get y(): number

    get z(): number

    get w(): number
  }

  export interface Image2DOption {
    level?: number;
    internalFormat?: InternalFormat;
    width?: number;
    height?: number;
    border?: number;
    format?: InternalFormat;
    type?: IndicesType;
    data?: ArrayBuffer;
  }

  export interface UpdateImage2DOption extends Image2DOption {
    xoffset?: number,
    yoffset?: number,
  }

  /**
   * @since 0.2.0
   */
  export class Texture {
    constructor(type?: TextureTarget)

    /**
     * texture handle
     */
    get id(): number

    /**
     * texture type
     */
    get textureType(): TextureTarget

    setParameter(name: TexParamName, value: number): Texture

    image2D(option?: Image2DOption): void;

    updateImage2D(option: UpdateImage2DOption)


    generateMipMap(): void

    bindActive(target?: number): void

    delete(): void

    bind(): void
  }


  export class VertexArray {
    constructor()

    get id(): number

    bind()

    unbind()

    enable(attributeIndex: number)

    disable(attributeIndex: number)

    drawArrays(mode: DrawMode, first: number, count: number)

    drawElements(mode: DrawMode, count: number, indices: Uint8Array | Uint16Array | Uint32Array)

    setBuffer(buffer: Buffer, index: number, size: number, type: IndicesType, normalized: boolean, stride: number,
      pointer: number)

    /**
     * @deprecated
     * VertexArrayBinding
     */
    binding(vertexIndex: number)

    delete(): void
  }

  /**
   * @since 0.2.2
   * */
  export class NativeImage {
    constructor()

    constructor(texture: Texture)

    constructor(texture_id: number)

    get surfaceId(): string

    /**是否有可用帧*/
    get isAvailable(): boolean

    get textureId(): number

    /**将NativeImage实例附加到当前OpenGL ES上下文, 且该OpenGL ES纹理会绑定到
     GL_TEXTURE_EXTERNAL_OES, 并通过NativeImage进行更新*/
    attachContext(texture_id: number): OHNativeErrorCode

    /**NativeImage实例从当前OpenGL ES上下文分离*/
    detachContext(): OHNativeErrorCode

    /**
     * 更新纹理
     */
    updateSurfaceImage(): OHNativeErrorCode

    destroy(): void
  }


  export enum OHNativeErrorCode {
    /** @error succeed */
    NATIVE_ERROR_OK = 0,
    /** @error input invalid parameter */
    NATIVE_ERROR_INVALID_ARGUMENTS = 40001000,
    /** @error unauthorized operation */
    NATIVE_ERROR_NO_PERMISSION = 40301000,
    /** @error no idle buffer is available */
    NATIVE_ERROR_NO_BUFFER = 40601000,
    /** @error the consumer side doesn't exist */
    NATIVE_ERROR_NO_CONSUMER = 41202000,
    /** @error uninitialized */
    NATIVE_ERROR_NOT_INIT = 41203000,
    /** @error the consumer is connected */
    NATIVE_ERROR_CONSUMER_CONNECTED = 41206000,
    /** @error the buffer status did not meet expectations */
    NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,
    /** @error buffer is already in the cache queue */
    NATIVE_ERROR_BUFFER_IN_CACHE = 41208000,
    /** @error the buffer queue is full */
    NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000,
    /** @error buffer is not in the cache queue */
    NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,
    /** @error the consumer is disconnected */
    NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,
    /** @error the consumer not register listener */
    NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,
    /** @error the current device or platform does not support it */
    NATIVE_ERROR_UNSUPPORTED = 50102000,
    /** @error unknown error, please check log */
    NATIVE_ERROR_UNKNOWN = 50002000,
    /** @error hdi interface error */
    NATIVE_ERROR_HDI_ERROR = 50007000,
    /** @error ipc send failed */
    NATIVE_ERROR_BINDER_ERROR = 50401000,
    /** @error the egl environment is abnormal */
    NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000,
    /** @error egl interface invocation failed */
    NATIVE_ERROR_EGL_API_FAILED = 60002000,
  }

}


