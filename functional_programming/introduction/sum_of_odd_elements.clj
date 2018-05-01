(fn[lst]
	(reduce + (filter odd? lst))
)
