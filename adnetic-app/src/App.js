import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

class App extends Component {
  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h1 className="App-title">AdNetic</h1>
        </header>
        <p className="App-intro">
          The Adnetic advertisement searching project for company websites developed in the CmpE 130 Advanced Algorithms course.
          By Thinh Le, Kyle Ma, and Alondra Cabrera Ruiz
        </p> 
      </div>
    );
  }
}

export default App;
