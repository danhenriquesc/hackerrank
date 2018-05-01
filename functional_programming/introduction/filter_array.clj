(use '[clojure.string :only (split triml)])

(
	let [
		n_t (read-line) 
		n (Integer/parseInt n_t) 
	]

	(
        loop [a0 n]
        (when (> a0 0)
			(
	            let [
	              x_t (read-line) 
	              x (Float/parseFloat x_t) 
	            ]
	            
	            (println 
	            	(format "%.4f"
	                    (reduce  +
	                        (map
	                            (fn[i] (/ (reduce * (repeat i x)) (reduce * (range 1 (+ i 1)))))
	                            (range 10)
	                        )
	                    )
	                )
	            )
          	)
		(recur (- a0 1) ) )
	)

)
