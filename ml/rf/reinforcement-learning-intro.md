## RF in short

Agent interacts with the env to achieve certain goals. 

Actor goes from state to state. Takes actions in each state. After each action gets a reward.

At each step *t* agent receives observation Ot (and reward Rt), executes action At. The env receives action At and emits
observation Ot+1 and reward Rt+1.

Agent learns to make decisions.

## Why RF?

- Find previously unknown solutions
- Find solutions online (for unforseen circumstances)

`RF is science of learning to make decisions from interaction.`

## How RF is different from other types of learning?

- No supervision (no labeled data), only *reward* feedback
- Feedback can be delayed
- Time matters
- Earlier decisions affect later interactions

## Core concepts

- Environment
- Reward
- Agent, containing
    - Agent state
    - Policy
    - Value function (Q function)
    - Model (opt)


## Reward and Return

**Reward** is a scalar feeback signal. Indicates how well the agent is doing, is it acting in the right way.

**Return** is a sum of all the rewards for all the agent's lifecycle (or until the final state). Cumulative reward.
```
G1 = sum(R1 + R2 + ... + Rn +...)
```

So the reward is dependent on infinite number of rewards. In practice, we of course do not have access to all those rewards, so we approximate the Return.


`The goal of learning is to maximize Return.`

## Reward Hypotesis

`Any goal can be formalized as outcome of maximizing return`

## Value function

Expected return of the state s. It tells how good is it to be in a state s. Its a function which maps states to some real number.

```
v(s) = E[Gt | St = s] = E[Rt+1 + Rt+2 + .. | St = s]
```

Retuns and values can be defined recursively

```
Gt = Rt+1 + Gt+1
```

Actually it is also conditioned on policy. So, value function has different values for different policies.

```
v_PI(s) = E[Gt | St = s, PI] = E[Rt+1 + Y*Rt+2 + Y^2*Rt+3 .. | St = s, PI]
```

Also, there is usually the discount factor Y [0, 1]. Trades off importance of immediate a action VS long-term rewards. With Y you can discout future rewards in favor of the immediate ones. Makes the agent act NOW (quickly) rather then later.

Value function can be used to:
- Evaluate the desirability of states
- Select actions

Typically we dont have access to the true value function so we approximate it.

Now going to recursive form again.

```
Bellman equation 

v_PI(s) = E[Rt+1 + Y*Gt+1 | St =s, At ~ PI(s)] =
E[Rt+1 + Y*v_PI(St+1) | St =s, At ~ PI(s)]
```

Optimal value. Highest possible value for any policy. Does not depend on policy. For each state select the action the maximizes return and take the optimal value for all the next states. 
The optimal policy then would be to take all those actions.

```
v*(s) = max E[Rt+1 + Y*v_PI(St+1)| St =s, At = a] 
```



## Q function

Pretty much the same as value func by also conditioned on action.

```
q(s,a) = E[Gt | St = s, At = a]
```

Tells us how good it is to take action a in a state s. In the end its a function which maps (s, a) pairs to some real number.

## Policy

It's a function, which maps states to actions. 

Can be deterministic:  `A = PI(S)`

Or stochastic: `PI(A|S) = P(A|S)`

## State

### Agent state

- Agent state is a function of its history (S - A - R - O - new S)

`St+1 = f(St, At, Rt+1, Ot+1)` f is *state update function*
- Actions depend on a state of an agent. 
- Simple examle is when we just make our agents state = observation
- Often there are infinetely many states. 
- The state of the agent generally differs from the state of the env. Usually it is much lower number.

Examples of the agent states
- St = Ot. Might not be enogph, when env is partially observable.
- St = Ht. Too large.
- St = f(St-1, Ot). RNN can be used here. E.g. concatenate a couple of frames for a robot with a camera.

Constructing a Markov state may not be feasible.

Statr should contains enough information to construct a good policy.

### Env state

- It is not usually visible to the agent
- Even if its visible can contain lots of irrelevent info

## Markov decision process

Is a math framework.

A decision process is Markov if
`p(r,s|St, At) = p(r,s|Ht,At)`
Ht is a history from H0 up to Ht (OtAtRtOt+1...)

- The future is independent of the past given the present
- All the needed info to predict the future is already contained in the current state
- Once the state is known the history may be thrown away
- The environment state is typically Markov

## Full observability

Agent state = env state. 

E.g. a board game.

## Partial observability

Agent sees only some part of env state.

E.g. robot with a camera.

`POMDP - Partially observable MDP.`

Env can be markovian, but the robot does not know it. So diffenrt states of the env can be seens by the agent as identical (e.g. similiar edges in different parts of a maze). 
In this case agent can keep several previous states to distinguish between these seemingly similiar states.


## Agent categories

- Value based
    - Value function (we construct a policy from this values)
- Policy based
    - Policy (no notion of value f)
- Actor Critic
    - Policy (Actor)
    - Value f (Critic)





