#pragma once

#include "Shader.hpp"
#include <SDL.h>
#include <memory>
#include <glm/glm.hpp>
#include <ocl.h>


#include <CL/opencl.h>

enum SboChannel
{
	State1 = 0
	, State2 = 1
	, Counter = 2
	, Positions = 3
	, END = 4 // keep at the end
};

class App
{
public:
	App();
	~App();
	App(const App &) = delete;
	App(App &&) = delete;
	App &operator=(const App &) = delete;
	App &operator=(App &&) = delete;
	bool init();
	void generateBuffers(GLuint particleNumber);
	void generateBuffers();
	bool run();
	bool deactivate();
	void loadShaders();
	bool _updateInput();
private:
	ocl_device _device;
	ocl_kernel _computeNewStateShader;
	ocl_kernel _copyOldStateShader;
	int injectPoint;
	std::unique_ptr<OpenGLTools::Shader> _renderShader;
	SDL_Window *_window;
	unsigned int _width;
	unsigned int _height;
	GLuint _workGroupSize;
	SDL_GLContext _context;
	GLuint _sbos[SboChannel::END];
	cl_mem _clSbos[SboChannel::Positions];
	float _totalTime;
	float _deltaTime;
	std::size_t _pastTime;
	SboChannel _read;
	SboChannel _write;
	bool _inject;
	glm::uvec2 _injectCoord;
	int _cancerPercent;
	int _healthyPercent;
	float _zoom;
	size_t total;

	void _clean();

	/*cl_program loadProgram(std::string &filename)
	{
		auto ph = fopen(filename.c_str(), "r");
		fseek(ph, 0, SEEK_END);
		const size_t ps = ftell(ph);
		rewind(ph);

		auto pb = (char*)malloc(ps + 1);
		pb[ps] = '\0';
		fread(pb, sizeof(char), ps, ph);
		fclose(ph);
		auto p = clCreateProgramWithSource(_cl_context, 1, (const char **)pb, &ps, nullptr);
		static const char options[] = "-cl-std=CL1.1 -cl-mad-enable -Werror";
		auto err = clBuildProgram(p, 1, _devices, options, nullptr, nullptr);
		if (err < 0)
		{
			std::size_t logSize;
			clGetProgramBuildInfo(p, _devices[0], CL_PROGRAM_BUILD_LOG,
				0, nullptr, &logSize);
			auto program_log = (char*)calloc(logSize + 1, sizeof(char));
			clGetProgramBuildInfo(p, _devices[0], CL_PROGRAM_BUILD_LOG,
				logSize + 1, program_log, NULL);
			printf("%s\n", program_log);
			free(program_log);
		}
	}*/
};