SELECT  o.animal_id, o.name
FROM    animal_ins as i right outer join animal_outs as o 
        on i.animal_id = o.animal_id
WHERE   i.animal_id is null
order by animal_id;