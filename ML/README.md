# ML Tests

## Running Conda with CUDA Support and a Jupyter Notebook

To run Jupyter Noteboook with CUDA:

- Execute on the command line:
```
docker run --gpus all --rm -i -t -p 8888:8888 openiss-cuda-conda-jupyter:F22-01 /bin/bash -c "/opt/conda/bin/jupyter notebook --notebook-dir=/opt/notebooks --ip='*' --port=8888 --no-browser --allow-root"
```
- Open browser with the IPv4 link printed on the conosole to login to Juypter notebook
- Load your notebook
- While running if need to install packages in the container open terminal from Docker Desktop and use the standard commands to install packages.

Resources:

- Docker file: `Dockerfile.jupyter-conda`
- Binary image on the dockerhub: https://hub.docker.com/r/openiss/openiss-cuda-conda-jupyter/tags

## OpenISS Re-identification Applicaiton using YOLO

To run:

- Execute:
```
docker run --name oi-reid --gpus all --rm -e DISPLAY=<your_ipv4_address>:0.0 openiss-reid:F22-01
```
- Init and activate conda enviroment inside the container as needed

Resources:

- Docker file: `Dockerfile.oi-reid`
- Binary image on the dockerhub: https://hub.docker.com/r/openiss/openiss-reid/tags
