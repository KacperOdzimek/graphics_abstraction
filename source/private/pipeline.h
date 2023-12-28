#pragma once

namespace graphics_abstraction
{
	struct object;
	struct framebuffer;
	struct buffer;
	struct shader;
	struct vertex_layout;
	struct textures_selection;

	namespace internal
	{
		struct pipeline
		{
			framebuffer*		framebuffer			= nullptr;
			shader*				shader				= nullptr;
			buffer*				vertex_buffer		= nullptr;
			vertex_layout*		vertex_layout		= nullptr;
			buffer*				indices_buffer		= nullptr;
			textures_selection* textures_selection 	= nullptr;
		};

		inline bool is_binded(pipeline& pipeline, object* obj)
		{
			return (
				(void*)pipeline.framebuffer				== (void*)obj ||
				(void*)pipeline.shader					== (void*)obj ||
				(void*)pipeline.vertex_buffer			== (void*)obj ||
				(void*)pipeline.vertex_layout			== (void*)obj ||
				(void*)pipeline.indices_buffer			== (void*)obj ||
				(void*)pipeline.textures_selection		== (void*)obj
			);
		}

		inline void unbind(pipeline& pipeline, object* obj)
		{
			if ((void*)pipeline.framebuffer == (void*)obj)
				pipeline.framebuffer = nullptr;

			else if ((void*)pipeline.shader == (void*)obj)
				pipeline.shader = nullptr;

			else if ((void*)pipeline.vertex_buffer == (void*)obj)
				pipeline.vertex_buffer = nullptr;

			else if ((void*)pipeline.vertex_layout == (void*)obj)
				pipeline.vertex_layout = nullptr;

			else if ((void*)pipeline.indices_buffer == (void*)obj)
				pipeline.indices_buffer = nullptr;

			else if ((void*)pipeline.textures_selection == (void*)obj)
				pipeline.textures_selection = nullptr;
		}
	}
}