(defn hello_word_n_times[n]
    (when (> n 0)
        (println "Hello World")
        (recur (- n 1))
    )
)