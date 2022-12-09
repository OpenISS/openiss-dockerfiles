# Running OpenGL Programs from Docker

First, complete X11 server setup and test it.
See [X11](../X11) for instructions and quick graphics tests after the setup is done.
Having made sure the graphics is working can test OpenGL examples or any windowing
applications from within the containers.

## Images

The `Dockerfile.base` provides the common base image for all samples. The images
can be built from scratch or pulled.

- Base OpenGL image for all projects: https://hub.docker.com/r/openiss/openiss-opengl-base/tags
- Blank OpenGL window: https://hub.docker.com/r/openiss/openiss-opengl-glfw/tags
- Simple OpenGL triangle: https://hub.docker.com/r/openiss/openiss-opengl-triangle/tags
- A interactive 3D world of simple cubes: https://hub.docker.com/r/openiss/openiss-opengl-cubes/tags

### Running the OpenGL examples

To run the OpenGL examples, build and run them with their respective Dockerfiles, e.g.:

```
docker build -f Dockerfile.cubes . -t cubes
docker run --rm --name cubes -e DISPLAY=<your_ipv4_address>:0.0 cubes:latest
```

You can test GLFW by building `Dockerfile.glfw` and the triangle OpenGL example using `Dockerfile.glfw`.

The `Dockerfile.skeleton` depeonstrates a student OpenGL project that tests
OpenISS skeleton tracking framework using null software devices (no drivers for actual cameras).

If rebuilding with NVIDIA or AMD drivers make sure to pass the `--gpus all` option to `docker run`.
