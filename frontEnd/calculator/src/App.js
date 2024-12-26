import React, { useState } from 'react';
import { format } from 'date-fns';
import './App.css';


function App() {

  const [daysUser, setDaysUser] = useState(0);
  const [monthsUser, setMonthsUser] = useState(0);
  const [yearsUser, setYearsUser] = useState(0);
  const currentDate = new Date();
  const formattedDay = format(currentDate, 'dd');
  const formattedMonth = format(currentDate, 'MM');
  const formattedYears = format(currentDate, 'yyyy');


  const daysRest = formattedDay - daysUser;
  const daysRestFinal = daysRest < 0 ? 1 : 0;
  const ageMonth = formattedMonth < monthsUser ?  formattedMonth - monthsUser + 12:formattedMonth - monthsUser + daysRestFinal;

  const ageNow =  formattedMonth < monthsUser ? formattedYears - yearsUser - 1: formattedYears - yearsUser ;
  const ageDays = Math.floor(formattedDay % daysUser); 

  return (
    <div className='geralBlock'>
    <article className='topBlock'>
      <div> 
          Day
          <input
            onChange={e => setDaysUser(e.target.value)}
            type="number"
          />
          
        </div>
      
      <div>
          Month
          <input
            onChange={e => setMonthsUser(e.target.value)}
            type="number"
          />
        </div>

        <div>
          Year
          <input
            onChange={e => setYearsUser(e.target.value)}
            type="number"
          />
        </div>
        
      </article>
      <img src="./assets/images/icon-arrow.svg" alt='icon'/>
      <article className='result'>
        
        <div>
            <p><a className="result-number">{ageNow}</a> years</p>
            <p><a className="result-number">{ ageMonth }</a> month</p>
            <p><a className="result-number">{ ageDays }</a> days</p>
        </div>
        
      </article>
      </div>
  );
}

export default App;
