
	t_envp *first = args->envp2;
	while (first)
	{
		printf("%s:%s\n", first->name, first->value);
		first = first->next;
	}
