SELECT i.animal_id, i.name
FROM animal_ins as i 
join animal_outs as o
on i.animal_id = o.animal_id
WHERE o.datetime < i.datetime
order by i.datetime asc