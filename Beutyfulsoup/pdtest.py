# importiong the modules 
import pandas as pd 
import numpy as np 
  
# creating the Numpy array 
array = np.array([[1, 1, 1], [2, 4, 8], [3, 9, 27],  
                  [4, 16, 64], [5, 25, 125], [6, 36, 216],  
                  [7, 49, 343]]) 
  
# creating a list of index names 
index_values = ['first', 'second', 'third', 
                'fourth', 'fifth', 'sixth', 'seventh'] 
   
# creating a list of column names 
column_values = ['number', 'squares', 'cubes'] 
  
# creating the dataframe 
df = pd.DataFrame(data = array,  
                  index = index_values,  
                  columns = column_values) 
  
# displaying the dataframe 
print(df) 