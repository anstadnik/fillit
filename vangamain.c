int main()
{
	t_params	*params;
	t_colobj	*head;
	char		*solution;

	if (!t_params = check(argv[1]) || !head = createsheet(params, argv[1]))
		error;
	while (!solution = solve(head, params))
	{
		params->size++;
		clean(head);
		if (!head = createsheet(params, argv[1]))
			error;
	}
	clean(head);
	print(solution);
	return (0);
}
