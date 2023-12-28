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
		void set_color_buffer(texture* _color_buffer)
		{
			color_buffer = _color_buffer;
			set_color_buffer_impl();
		}
		void set_depth_stencil_buffer(texture* _depth_stencil_buffer)
		{
			depth_stencil_buffer = _depth_stencil_buffer;
			set_depth_stencil_buffer_impl();
		}
		virtual texture* get_color_buffer() final
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