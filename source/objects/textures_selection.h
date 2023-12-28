#pragma once

namespace graphics_abstraction
{
	struct textures_selection : public object
	{
	protected:
		std::vector<texture*> textures;
	protected:
		virtual void bind(internal::pipeline& pipeline) final
		{
			pipeline.textures_selection = this;
		}

	public:
		virtual void set_selection(std::vector<texture*> _textures) final
		{
			textures = _textures;
		}
	};

	struct textures_selection_builder : public builder
	{
		std::vector<texture*> textures;
	protected:
		virtual object* build_abs(api*& api) final
		{
			return this->build_impl(api);
		}
	};
}