# openfaas-c

OpenFaaS template for the C programming language

## Getting started

The following dependencies must be installed before anything else:

* Docker CE 17.05 or later (for use on Swarm);
* Bash;
* Git.

## Setting up

The following lines will show you how to prepare the environment and deploy
a simple serverless C function using Docker Swarm as cluster. Check out the
official [documentation](docs.openfaas.com) to learn how to use Kubernetes.

## OpenFaaS installation

> Cloning the official OpenFaaS repository on your workspace

```
$ git clone https://github.com/openfaas/faas
```

> Initializing Swarm

```
$ docker swarm init
```

**Note**: if you have more than one active Ethernet adapter, you must specify
one through `--advertise-addr` flag.

> Deploying the FaaS stack

```
$ cd faas
$ ./deploy_stack.sh
```

At this point, the OpenFaaS UI is already available at `http://localhost:8080` or
at the ip address corresponding to the specified Ethernet adapter (`http://192.168.100.1:8080`, for example).
Don't forget to save the credentials generated. They are used for authentication by UI and FaaS CLI interface.

> Installing the CLI

The CLI is a useful way to interact with OpenFaaS functions. To install it, type:

```
$ curl -sSL https://cli.openfaas.com | sudo sh
```

Now everything is set and you're ready to go.

## Building and deploying your function

Create a template folder and clone this repository inside a c/ folder inside it:

```
$ mkdir template && mkdir template/c && cd template/c
$ git clone https://github.com/lucasfsduarte/openfaas-c.git
```

> Creating a C function

```
$ faas-cli new --lang c hello-c
```

After that, a `hello-c.yml` file and a `hello-c/` folder will be generated. You
can edit the code inside `hello-c/` to make whatever you want.

> Building

```
$ faas-cli build -f hello-c.yml
```

> Deploying

```
$ faas-cli deploy -f hello-c.yml
```

Done! You can access the deployed function through UI or `faas-cli invoke` command.

## Solving problems

Sometimes is necessary to run `faas-cli login` in order to build and/or deploy
your functions. The parameters are the username and password generated on FaaS
stack deploy step. You may also need to inform the Ethernet interface through
`--gateway` flag.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
