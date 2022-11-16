# OpenISS Dockerfiles

For teaching, learnding, and HPC research.

Use OpenGL versions primarily for graphics rendering.
Use CUDA versions primarily for ML stuff.

The containers provided here are possible starter sample containers
that extend existing ones with samples preloaded or build new ones.
Some are very simple and basics, while others are more complete.
Feel free to choose any applicable ones.

There is a choice of either building a container locally using its Dockerfile
script or pulling pre-built images, whichever is faster.

We then include complete OpenISS inside the container for image and motion
data processing.

If you want to reproduce the setup on Windows the documentation is below.

# Sample containers

TL;DR

- Versioning: season-sequence number, e.g., `W22-01`

Small vanilla sample containers:

OpenGL:

- `openiss-opengl-ogl` -- OpenISS OGL extension samples
- `openiss-opengl-sample-projects` -- all inclusive
- `openiss-opengl-cubes:W22-01` -- simple cubes example
- `openiss-opengl-glfw:W22-01` -- example of using GLFW
- `openiss-opengl-triangle:W22-01` -- simple triangle
- `openiss-xeyes:W22-01` -- X11 test

CUDA:

- `openiss-cuda-device-query:W22-01`, includes official `cuda-samples`
- `openiss-cuda-opengl:W22-01`, includes official `cuda-samples` (not supported on Windows WSL)

ML:

- `openiss-lambdal-stack`

## Sources

- [CUDA](CUDA/) -- CUDA-specific samples
- [OpenGL](OpenGL/) -- OpenGL-specific samples

## Pulling

```
docker pull openiss/openiss-ws
```

To pull a specific tag, suffix it at the end of the pull:

```
docker run --rm -it --gpus=all openiss/openiss-ws:01
```

## Running 

```
docker run --rm -it --gpus=all openiss/openiss-ws:01
```

# Setting up

## Setting up NVidia Docker on Windows

### Step 1: Get correct Windows version

Ensure that Windows OS is Windows 10 version 21H2 or higher, or Windows 11.

You can check by looking by using `winver` in the terminal.

![winver](images/Windows_Version.png)

### Step 2: Setup WSL

From [https://docs.microsoft.com/en-us/windows/wsl/install](https://docs.microsoft.com/en-us/windows/wsl/install)

In an **administrator** PowerShell or Windows Command Prompt type:

```
wsl --install
```

Then restart the computer.

Go back to a command prompt and type:

```
wsl --set-default-version 2
```

### Step 3: Get Linux (Ubuntu 20.04 LTS)

You can either get it from the Microsoft App Store

or

Type the following into a terminal:

```
wsl --install -d Ubuntu-20.04
```

Check that Ubuntu is running on the correct version of WSL using the following
in cmd:

```
wsl -l -v
```

Ubuntu should have a "2" in the version column

### Step 4: Get Docker

Download and install docker desktop from [https://docs.docker.com/desktop/windows/wsl/](https://docs.docker.com/desktop/windows/wsl/)

Once it is downloaded, go to settings and make sure it WSL integration is set to use Ubuntu.

![Docker settings](images/Docker_setup.png)

### Step 5: Setup CUDA

Install the appropriate NVidia drivers and CUDA Toolkit on Windows. And then do the same for Ubuntu.

Follow the steps given at...

[https://docs.nvidia.com/cuda/wsl-user-guide/index.html](https://docs.nvidia.com/cuda/wsl-user-guide/index.html)

or

[https://ubuntu.com/tutorials/enabling-gpu-acceleration-on-ubuntu-on-wsl2-with-the-nvidia-cuda-platform](https://ubuntu.com/tutorials/enabling-gpu-acceleration-on-ubuntu-on-wsl2-with-the-nvidia-cuda-platform)

### Step 6: Test that the GPU is accessible from Ubuntu

In a Windows command prompt type:

```
nvidia-smi
```

And then in the Ubuntu terminal type the same command.

The results should  be the same. If it is then setup is done.

### Step 7: Run the Docker NVidia test.

In a Windows command prompt run the following:

```
docker run --rm -it --gpus=all nvcr.io/nvidia/k8s/cuda-sample:nbody nbody -gpu -benchmark
```

This should also work in an Ubuntu terminal.

## Setting up on macOS

TODO

## Setting up on Linux

TODO

## References

TODO
