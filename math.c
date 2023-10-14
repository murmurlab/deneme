// hdeniz

int
	ft_isnan(register double x)
{
	return (x != x);
}
double
	ft_fabs(register double x)
{
	if (ft_isnan(x))
		return (-(0.0 / 0.0));
	if (x < 0.0)
		return (x * -1.0);
	return (x);
}
