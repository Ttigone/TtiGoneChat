#include "config.h"

namespace Proto
{
	Config::Config()
	{
	}

	Config::Config(const Config& other)
	{
	}

	const ConfigFields& Config::values() const
	{ return fields_;
	}
} // namespace Proto