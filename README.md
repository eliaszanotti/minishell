# MINISHELL

## Table of Contents

1. [Instalation](#instalation)
2. [Errors](#errors)
3. [Utils](#utils)

## Instalation 

```bash
git clone https://github.com/eliaszanotti/minishell.git
```

To install minishell you just have to clone the project and run the following command:

```c
make
```

## Errors

**[ERROR:2]** Command not found

**[ERROR:3]** Parse error (quote not closed)

**[ERROR:4]** Parse error on pipe

**[ERROR:5]** Syntax error on redirect

**[ERROR:6]** Parse error at end of command

**[ERROR:10]** Failed to create fork

**[ERROR:11]** Failed to pipe fd

**[ERROR:12]** Failed to execute command

**[ERROR:13]** Failed to duplicate fd (dup2 error)

**[ERROR:14]** Can't open file

**[ERROR:15]** Can't create file

**[ERROR:20]** No such file or directory

**[ERROR:99]** Malloc cannot be created

## Utils

**ft_log**

```c
static void	ft_u(t_list *in)
{
	while (in)
	{
		printf("[%s]", (char *)in->content);
		in = in->next;
	}
	printf("\n");
}

void	ft_log(t_list *stack)
{
	while (stack)
	{
		ft_u(stack->content);
		stack = stack->next;
	}
	printf("%p\n", stack);
}
```

**ft_logg (envp log)**

```c
int	ft_logg(t_args *args)
{
	t_envp	*envp;

	envp = args->envp;
	while (envp)
	{
		printf("%d ", envp->equal);
		printf("%s=%s\n", envp->name, envp->value);
		envp = envp->next;
	}
	return (0);
}
```
