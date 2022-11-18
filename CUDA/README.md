# CUDA Tests

There are few dockerfiles which build from the nvidia/cuda image on hub.docker...

These examples are built from the Ubuntu 20.04 Nvidia CUDA image (specifically, nvidia/cuda:11.7.1-devel-ubuntu20.04) on [Docker Hub](https://hub.docker.com) using the the [cuda-samples](https://github.com/NVIDIA/cuda-samples) repo.


## Device query test

This will build the [deviceQuery](https://github.com/NVIDIA/cuda-samples/tree/master/Samples/1_Utilities/deviceQuery) program from cuda-samples.

```
docker build -t device-query -f Dockerfile.deviceQuery .
```

To run it you need to use the `--gpus` flag or else it will fail:
```
docker run --name device-query --gpus all --rm deviceQuery:latest
```

## OpenGL (non-functional on Windows)

**Warning:** This will not work with WSL because it is not supported yet. See: [https://docs.nvidia.com/cuda/wsl-user-guide/index.html#features-not-yet-supported](https://docs.nvidia.com/cuda/wsl-user-guide/index.html#features-not-yet-supported)

This will build the [simpleGL sample](https://github.com/NVIDIA/cuda-samples/tree/master/Samples/5_Domain_Specific/simpleGL)

```
docker build -t simple-gl -f Dockerfile.simpleGL .
```

To run it use the you need to use the `--gpus` flag and a have an X server running (See OpenGL examples).

```
docker run --name simple-gl --gpus all --rm -e DISPLAY=<your_ipv4_address>:0.0 simpleGL:latest
```
