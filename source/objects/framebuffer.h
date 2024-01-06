#pragma once

namespace graphics_abstraction
{
	
	struct framebuffer : public object
	{
	protected:
		texture* color_buffer;
		texture* depth_stencil_buffer;

		virtual void bind(internal::pipeline& pipeline) final
		{
			pipeline.framebuffer = this;
		}
	
		virtual void set_color_buffer_impl() = 0;
		virtual void set_depth_stencil_buffer_impl() = 0;

	public:
<<<<<<< Updated upstream
		void set_color_buffer(texture* _color_buffer)
=======
		virtual void set_color_buffer(uint8_t number, texture* color_buffer) final
>>>>>>> Stashed changes
		{
			color_buffer = _color_buffer;
			set_color_buffer_impl();
		}
		virtual void set_depth_stencil_buffer(texture* _depth_stencil_buffer) final
		{
			depth_stencil_buffer = _depth_stencil_buffer;
			set_depth_stencil_buffer_impl();
		}
<<<<<<< Updated upstream
		virtual texture* get_color_buffer() final
=======
		virtual void clear_color_buffers(float r, float g, float b, float a) = 0;
		virtual void clear_depth_buffer() = 0;
		virtual void clear_stencil_buffer() = 0;
		virtual texture* get_color_buffer(uint8_t number) final
>>>>>>> Stashed changes
		{
			return color_buffer;
		}
		virtual texture* get_depth_stencil_buffer() final
		{
			return depth_stencil_buffer;
		}
	};

	struct framebuffer_builder : public builder
	{
		texture* color_buffer = nullptr;
		texture* depth_stencil_buffer = nullptr;
	protected:
		virtual object* build_abs(api*& api) final
		{
			return this->build_impl(api);
		}
	};
}